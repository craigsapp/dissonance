## hum2ly GNU makefile 
##
## Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
## Creation Date: Sat Aug  6 10:57:54 CEST 2016
## Last Modified: Sun Sep 18 12:31:52 PDT 2016
## Filename:      dissonance/Makefile
##
## Description: This Makefile compiles the dissonance program.
##
## To run this makefile, type (without quotes) "make" (or
## "gmake library" on FreeBSD computers).
##

# targets which don't actually refer to files:
.PHONY: external tests humlib
.SUFFIXES:

OBJDIR    = obj
SRCDIR    = src
INCDIR    = include
BINDIR    = bin
TARGET    = dissonance
INCDIRS   = -I$(INCDIR)
INCDIRS  += -Iexternal/humlib/include 
LIBDIRS   = -Lexternal/humlib/lib
HUMLIB    = humlib
COMPILER  = g++
PREFLAGS  = -Wall -O3 $(INCDIRS)
POSTFLAGS = $(LIBDIRS) -l$(HUMLIB)

# Humlib needs C++11:
PREFLAGS += -std=c++11

# setting up the directory paths to search for dependency files
vpath %.h   $(INCDIR)
vpath %.cpp $(SRCDIR)
vpath %.o   $(OBJDIR)

# generating a list of the object files
OBJS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(patsubst %.cpp,%.o,$(wildcard $(SRCDIR)/*.cpp)))


all: objdir bindir external $(OBJS)
	@echo [CC] $(BINDIR)/$(TARGET)
	@$(COMPILER) $(PREFLAGS) -o $(BINDIR)/$(TARGET) $(OBJS) $(POSTFLAGS) 
#		&& strip $(BINDIR)/$(TARGET)

objdir:
	mkdir -p $(OBJDIR)


bindir:
	mkdir -p $(BINDIR)

update:
	git pull

install:
	sudo cp bin/dissonance /usr/local/bin/

external:
ifeq ($(wildcard external/humlib/lib/libhumlib.a),)
	(cd external && $(MAKE) humlib)
endif

install:
	sudo cp bin/dissonance /usr/local/bin

tests:
	for i in tests/*.xml; do ./$(TARGET) $$i > tests/`basename $$i .xml`.krn; done


clean:
	-rm $(OBJDIR)/*.o
	-rmdir $(OBJDIR)


superclean: clean
	(cd external && $(MAKE) clean)
	-rm $(BINDIR)/$(TARGET)
	-rmdir $(BINDIR)


###########################################################################
#                                                                         #
# defining an explicit rule for object file dependencies                  #
#                                                                         #

$(OBJDIR)/%.o : %.cpp
	@echo [CC] $@
	@$(COMPILER) $(PREFLAGS) -g -c -o $(OBJDIR)/$(notdir $@) $<


#                                                                         #
###########################################################################



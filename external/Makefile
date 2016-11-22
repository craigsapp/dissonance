## dissonance external makefile
##
## Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
## Creation Date: Sat Aug  6 10:00:27 CEST 2016
## Last Modified: Sat Aug  6 10:00:34 CEST 2016
## Filename:      ...dissonance/external/Makefile
##
## Description: This Makefile compiles external libraries used in
##              dissonance source code.  In particular:
##              (1) humlib for parsing Humdrum files.
##
## To run this makefile, type (without quotes) "make", or "gmake" on
## FreeBSD computers.  This makefile is typically run automatically from the
## parent directory's Makefile.
##

.PHONY: humlib 

all: humlib 

humlib:
ifeq ($(wildcard humlib),)
	wget https://github.com/craigsapp/humlib/archive/master.zip -O humlib.zip
	unzip humlib.zip
	mv humlib-master humlib
endif
	(cd humlib && make CFLAGS=-D_USE_HUMLIB_OPTIONS_)


clean:
	-rm -f humlib.zip
	-rm -rf humlib





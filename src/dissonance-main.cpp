//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Sat Aug  6 10:53:40 CEST 2016
// Last Modified: Sun Sep 18 13:11:26 PDT 2016
// Filename:      main.cpp
// URL:           https://github.com/craigsapp/dissonance/blob/master/src/main.cpp
// Syntax:        C++11
// vim:           ts=3 noexpandtab
//
// Description:   Dissonance idenfication and labeling tool.
//

#include "dissonance.h"

#include <iostream>

using namespace std;
using namespace hum;

int main(int argc, char** argv) {
	hum::dissonance_interface interface;
	hum::Options options = interface.getOptionDefinitions();
	options.process(argc, argv);

	HumdrumFile infile;
	string filename;
	if (options.getArgCount() == 0) {
		filename = "<STDIN>";
		infile.read(cin);
	} else {
		filename = options.getArg(1);
		infile.read(filename.c_str());
	}

cerr << "GOT HERE AAA" << endl;
	interface.setOptions(argc, argv);
cerr << "GOT HERE BBB" << endl;
	bool status = interface.process(infile);
cerr << "GOT HERE CCC" << endl;
	if (!status) {
		cout << infile;
	}
cerr << "GOT HERE DDD" << endl;

	return 0;
}




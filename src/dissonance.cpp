//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Tue Nov 22 10:47:21 PST 2016
// Last Modified: Tue Nov 22 10:47:23 PST 2016
// Filename:      dissonance.cpp
// URL:           https://github.com/craigsapp/hum2ly/blob/master/src/dissonance.cpp
// Syntax:        C++11
// vim:           ts=3 noexpandtab
//
// Description:   Convert a MusicXML file into a Humdrum file.
//

#include "dissonance.h"

using namespace std;

namespace hum {


//////////////////////////////
//
// dissonance_interface::dissonance_interface --
//

dissonance_interface::dissonance_interface(void){
	Options& options = m_options;
	options.define("a|append=b","append analysis to input data");
	options.define("p|prepend=b","prepend analysis to input data");
}



//////////////////////////////
//
// dissonance_interface::setOptions -- Receive command-line options to the class.
//

void dissonance_interface::setOptions(const vector<string>& argvlist) {
	int tempargc = (int)argvlist.size();
	char* tempargv[tempargc+1];
	tempargv[tempargc] = NULL;

	int i;
	for (i=0; i<tempargc; i++) {
		tempargv[i] = new char[argvlist[i].size() + 1];
		strcpy(tempargv[i], argvlist[i].c_str());
	}

	setOptions(tempargc, tempargv);

	for (i=0; i<tempargc; i++) {
		if (tempargv[i] != NULL) {
			delete [] tempargv[i];
		}
	}
}



//////////////////////////////
//
// dissonance_interface::setOptions --
//

void dissonance_interface::setOptions(int argc, char** argv) {
	m_options.process(argc, argv);
}



//////////////////////////////
//
// dissonance_interface::getOptionDefinitions -- Used to avoid
//     duplicating the definitions in the test main() function.
//

Options dissonance_interface::getOptionDefinitions(void) {
	return m_options;
}



//////////////////////////////
//
// dissonance_interface::process -- Returns true if the HumdrumFile should be
//     printed to standard output after calling this function.
//

bool dissonance_interface::process(HumdrumFile& infile) {


	return true;
}




} // end namespace hum

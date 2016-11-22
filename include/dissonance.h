//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Tue Nov 22 10:42:20 PST 2016
// Last Modified: Tue Nov 22 10:42:23 PST 2016
// Filename:      dissonance.h
// URL:           https://github.com/craigsapp/dissonance/blob/master/include/dissonance.h
// Syntax:        C++11
// vim:           ts=3 noexpandtab
//
// Description:   Inteface to convert a MusicXml file into a Humdrum file.
//

#ifndef _DISSONANCE_H
#define _DISSONANCE_H

#include "humlib.h"

using namespace std;

namespace hum {


class dissonance_interface {
	public:
		dissonance_interface       (void);
		~dissonance_interface      () {}

		void    setOptions           (int argc, char** argv);
		void    setOptions           (const vector<string>& argvlist);
		Options getOptionDefinitions (void);

		bool    process              (ostream& out, HumdrumFile& infile);

	protected:

	private:
		Options m_options;

};


}  // end of namespace hum

#endif /* _DISSONANCE_H */




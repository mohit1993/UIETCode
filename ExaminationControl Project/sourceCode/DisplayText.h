#ifndef __DISPLAY_TEXT

#define __DISPLAY_TEXT

#include "StandardInclusions.h"

class DisplayText;

class DisplayText{
	public:
		static void display(string);
		static void showchar(int,int);

	private:
		static string characters[26][5];
};

#endif

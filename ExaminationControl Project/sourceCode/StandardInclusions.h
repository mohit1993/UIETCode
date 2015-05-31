#ifndef __StandardInclussion_H
#define __StandardInclussion_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include <ctime>
#include <cstdlib>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm;
        stm << n ;
        return stm.str() ;
    }
}

#ifdef _WIN32
	#define CLEAR "cls"
#elif linux
	#define CLEAR "clear"
#endif

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::setw;
using std::setprecision;
using std::setfill;
using std::ios;
using std::ofstream;
using std::ifstream;
using std::left;
using patch::to_string;
using std::right;


int getCurrentYear();
#endif
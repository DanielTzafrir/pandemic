#pragma once

#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

namespace pandemic {

	class Board
	{
	public:
		array<int, CITIES> cubs;
        	array<bool, CITIES> researchFacility;
        	array<bool, COLORS> cure;
		
		map <string, map<string, bool>> neighbors;

		Board();
		
		int& operator [] (City temp)
		{
			return cubs[temp];
		}

		void loadMaps();

		friend ostream& operator <<(ostream& os, Board b)
		{
			os << "this is a board print" << endl;
			
			return os;
		}

		bool is_clean();

		void remove_cures();
		
	};
}


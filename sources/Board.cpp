
#include "Board.hpp"

using namespace std;

namespace pandemic {

	Board::Board() : cubs{0}, researchFacility{false}, cure{false} {
        for ( const auto& city1 : cityNames ) {
            for ( const auto& city2 : cityNames ) {
                neighbors[city1][city2] = false;
            }
        }
        
        loadMaps();
    }
	void Board::loadMaps()
	{
		ifstream file("cities_map.txt");
		string str;

		string first_name;
		string city_name;
		while (getline(file, str))
		{
			bool f = false;
			int counter = 0;

			size_t a = 0;
			while ((a = str.find(' ')) != string::npos)
			{
				counter++;
				city_name = str.substr(0, a);
				if (!f)
				{
					f = true;
					first_name = city_name;
				}

				str.erase(0, a + 1);

				if (counter > 2) 
				{
					neighbors[first_name][city_name] = true;
					neighbors[city_name][first_name] = true;
				}
			}

			neighbors[first_name][str] = true;
			neighbors[str][first_name] = true;

		}
	}

	bool Board::is_clean()
	{
		unsigned int counter = 0;
		bool answer = true;

		while (counter < CITIES)
		{
			if (cubs.at(counter) != 0)
			{
				answer = false;
				break;
			}

			counter++;
		}

		return answer;
	}

	void Board::remove_cures()
	{
		for (unsigned int i = 0; i < COLORS; i++)
		{
			cure.at(i) = false;
		}
	}

}


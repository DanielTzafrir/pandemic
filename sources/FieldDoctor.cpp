
#include "FieldDoctor.hpp"

namespace pandemic
{
	FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city) {}

	Player& FieldDoctor::treat(City city)
	{

		if (board.cubs.at(city) != 0)
		{
			if (board.neighbors[cityNames[current_city]][cityNames[city]] || city == current_city)
			{
				unsigned int color_of_city = city / CITIES_PER_COLOR;

				if (board.cure.at(color_of_city))
				{
					board.cubs.at(city) = 0;
				}

				else
				{
					board.cubs.at(city) = board.cubs.at(city) - 1;
				}
			}

			else
			{
				throw invalid_argument("not a neighbors");
			}
		}

		else
		{
			throw invalid_argument("There is no infection in this city");
		}

		return *this;
	}

	string FieldDoctor::role()
	{
		return "FieldDoctor";
	}
}

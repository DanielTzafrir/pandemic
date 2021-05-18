
#include "Virologist.hpp"

namespace pandemic
{
	Virologist::Virologist(Board& board, City city) : Player(board, city) {}

	Player& Virologist::treat(City city)
	{
		if (board.cubs.at(city) != 0)
		{
			if (current_city != city)
			{
				if (cards.at(city))
				{
					cards.at(city) = false;
				}

				else
				{
					throw invalid_argument("You don't have a card of the 					city");
				}
			}
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
			throw invalid_argument("There is no infection in this city");
		}

		return *this;
	}

	string Virologist::role()
	{
		return "Virologist";
	}
}

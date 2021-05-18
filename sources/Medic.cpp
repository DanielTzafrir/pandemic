
#include "Medic.hpp"

namespace pandemic
{

	Medic::Medic(Board& board, City city) : Player(board, city) {}

	Player& Medic::drive(City city)
	{
		string dest = cityNames[city];
		string src = cityNames[current_city];

		if (board.neighbors[src][dest])
		{
			current_city = city;

			unsigned int current_city_color = current_city / CITIES_PER_COLOR;

			if (board.cure.at(current_city_color))
			{
				board.cubs.at(current_city) = 0;
			}
		}

		else
		{
			throw invalid_argument("the city is not connected to the current 				city");
		}

		return *this;
	}

	Player& Medic::fly_direct(City city)
	{
		if (cards.at(city))
		{
			current_city = city;
			cards.at(city) = false;

			unsigned int current_city_color = current_city / CITIES_PER_COLOR;

			if (board.cure.at(current_city_color))
			{
				board.cubs.at(current_city) = 0;
			}
		}
		else
		{
			throw invalid_argument("You don't have the card of this city");
		}

		return *this;
	}

	Player& Medic::fly_charter(City city)
	{
		if (cards.at(current_city))
		{
			cards.at(current_city) = false;
			current_city = city;

			unsigned int current_city_color = current_city / CITIES_PER_COLOR;

			if (board.cure.at(current_city_color))
			{
				board.cubs.at(current_city) = 0;
			}
		}

		else
		{
			throw invalid_argument("You don't have the card of this city");
		}

		return *this;
	}

	Player& Medic::fly_shuttle(City city)
	{
		if (board.researchFacility.at(current_city))
		{
			if (board.researchFacility.at(city))
			{
				current_city = city;

				unsigned int current_city_color = current_city / CITIES_PER_COLOR;

				if (board.cure.at(current_city_color))
				{
					board.cubs.at(current_city) = 0;
				}
			}

			else
			{
				throw invalid_argument("This city doesn't have a research 					facility");
			}
		}

		else
		{
			throw invalid_argument("your current city doesn't have a research 				facility");
		}

		return *this;
	}

	Player& Medic::treat(City city)
	{
		if (current_city == city)
		{
			if (board.cubs.at(city) != 0)
			{
				//unsigned int color_of_current_city = city / CITIES_PER_COLOR;

				//if (board.cure.at(color_of_current_city))
				//{
					board.cubs.at(city) = 0;
				//}

				//else
				//{
				//	board.cubs.at(city) = 0;
				//}
			}

			else
			{
				throw invalid_argument("There is no infection in the city");
			}
		}

		else
		{
			throw invalid_argument("this city is not your current city");
		}

		return *this;
	}

	string Medic::role()
	{
		return "Medic";
	}
}

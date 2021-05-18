
#include "Dispatcher.hpp"

namespace pandemic
{


	Dispatcher::Dispatcher(Board& board, City city) : Player(board, city) {}

	Player& Dispatcher::fly_direct(City city)
	{
		if (city == current_city)
		{
			throw invalid_argument("you cant fly to the current city");
		}
		
		if (board.researchFacility.at(current_city))
		{
			current_city = city;
		}
		
		else if (cards.at(city))
		{
			current_city = city;
			cards.at(city) = false;
		}
		
		else
		{
			throw invalid_argument("no reaserch facility in this city");
		}

		return *this;
	}

	string Dispatcher::role()
	{
		return "Dispatcher";
	}

}

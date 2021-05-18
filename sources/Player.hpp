#pragma once

#include "Board.hpp"
#include <stack>
#include <sstream>

using namespace std;

namespace pandemic {

	class Player
	{
	public:
		Board& board;
		City current_city;
		array<bool, CITIES> cards;
		string role_name;
		const int numbers_of_cards = 5;
		Player(Board& b, City c);

		virtual Player& drive(City city);

		virtual Player& fly_direct(City city);

		virtual Player& fly_charter(City city);

		virtual Player& fly_shuttle(City city);
		
		virtual Player& build();
		
		virtual Player& discover_cure(Color color);
	
		virtual Player& treat(City city);

		virtual string role();

		Player& take_card(City city);

	};
}

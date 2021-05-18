#pragma once
#include "Player.hpp"

namespace pandemic
{
	class Medic : public Player
	{
	public:

		Medic(Board& board, City city);

		Player& drive(City city);
		
		Player& fly_direct(City city);

		Player& fly_charter(City city);

		Player& fly_shuttle(City city);

		Player& treat(City city);

		string role();

	};
}

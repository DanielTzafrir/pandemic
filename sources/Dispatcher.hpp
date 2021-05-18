#pragma once
#include "Player.hpp"

namespace pandemic
{
	class Dispatcher : public Player
	{
	public:

		Dispatcher(Board& board, City city);

		Player& fly_direct(City city);
		
		string role();
	
	};
}
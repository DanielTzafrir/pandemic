#pragma once
#include "Player.hpp"

namespace pandemic
{
	class Scientist : public Player
	{
	public:

		int n;
		Scientist(Board& board, City city, int _n);

		Player& discover_cure(Color color);

		string role();		
	};
}

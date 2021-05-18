
#include "OperationsExpert.hpp"

namespace pandemic
{
	OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city) {}

	Player& OperationsExpert::build()
	{
		if (!board.researchFacility.at(current_city))
		{
			board.researchFacility.at(current_city) = true;
		}

		return *this;
	}

	string OperationsExpert::role()
	{
		return "OperationsExpert";
	}
}

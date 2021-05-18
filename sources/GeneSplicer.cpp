
#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic
{
	GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city) {}

	Player& GeneSplicer::GeneSplicer::discover_cure(Color color)
	{
		int counter = 0;

		stack<unsigned int> stack_of_cities;

		for (unsigned int i = 0; i < CITIES; i++)
		{
			if (cards.at(i))
			{
				stack_of_cities.push(i);
				counter++;
			}

			if (counter >= numbers_of_cards)
			{
				break;
			}
		}

		if (!board.cure.at(color))
		{
			if (board.researchFacility.at(current_city))
			{
				if (counter >= numbers_of_cards)
				{

					while (!stack_of_cities.empty())
					{
						cards.at(stack_of_cities.top()) = false;
						stack_of_cities.pop();
					}

					board.cure.at(color) = true;
				}

				else
				{
					throw invalid_argument("You dont have enough cards");
				}
			}

			else
			{
				throw invalid_argument("No reaserch in the city");
			}
		}

		return *this;
	}

	string GeneSplicer::role()
	{
		return "GeneSplicer";
	}

}

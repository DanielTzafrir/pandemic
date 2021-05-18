
#include "Scientist.hpp"

namespace pandemic
{

	Scientist::Scientist(Board& board, City city, int _n) : Player(board, city), n(_n) {}

	Player& Scientist::discover_cure(Color color)
	{
		int counter = 0;
		unsigned int first_city_color = color * CITIES_PER_COLOR;
		unsigned int last_city_color = color * CITIES_PER_COLOR + CITIES_PER_COLOR;
		stack<unsigned int> stack_of_cities_color;


		for (unsigned int i = first_city_color; i < last_city_color; i++)
		{
			if (cards.at(i))
			{
				stack_of_cities_color.push(i);
				counter++;
			}

			if (counter >= n)
			{
				break;
			}
		}

		if (!board.cure.at(color))
		{
			if (board.researchFacility.at(current_city))
			{
				if (counter >= n)
				{

					while (!stack_of_cities_color.empty())
					{
						cards.at(stack_of_cities_color.top()) = false;
						stack_of_cities_color.pop();
					}

					board.cure.at(color) = true;
				}

				else
				{
					throw invalid_argument("You dont have enough cards with 						the right color");
				}
			}

			else
			{
				throw invalid_argument("There is no research facility in");
			}
		}

		return *this;
	}

	string Scientist::role()
	{
		return "Scientist";
	}
}

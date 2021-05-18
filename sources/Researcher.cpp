
#include "Researcher.hpp"
using namespace std;
namespace pandemic
{

	Researcher::Researcher(Board& board, City city) : Player(board, city) {}

	Player& Researcher::discover_cure(Color color)
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

			if (counter >= numbers_of_cards)
			{
				break;
			}
		}

		if (!board.cure.at(color))
		{
			if (counter >= numbers_of_cards)
			{

				while (!stack_of_cities_color.empty())
				{
					cards.at(stack_of_cities_color.top()) = false;
					stack_of_cities_color.pop();
				}

				board.cure.at(color)= true;
			}

			else
			{
				throw invalid_argument("you dont have enough cards with this 				color");
			}
		}

		return *this;
	}

	string Researcher::role()
	{
		return "Researcher";
	}
}

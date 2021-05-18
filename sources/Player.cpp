

#include "Player.hpp"

using namespace std;

namespace pandemic {

	Player::Player(Board& b, City c) :cards{false}, board(b), current_city(c)
	{
		for (unsigned int i = 0; i < CITIES; i++)
		{
			cards.at(i) = false;
		}
	}

	Player& Player::drive(City city)
	{
		string dest = cityNames[city];
		string src = cityNames[current_city];

		if (city == current_city)
		{
			throw invalid_argument("you cant fly to the current city");
		}
		
		if (board.neighbors[src][dest])
		{
			current_city = city;
		}
		
		else
		{
			throw invalid_argument("the city is not connected to the current 				city");
		}

		return *this;
	}

	Player& Player::fly_direct(City city)
	{
		if (city == current_city)
		{
			throw invalid_argument("you cant fly to the current city");
		}
		
		if (cards.at(city))
		{
			current_city = city;
			cards.at(city) = false;
		}
		else
		{
			throw invalid_argument("You don't have the card of this city");
		}

		return *this;
	}

	Player& Player::fly_charter(City city)
	{
		if (city == current_city)
		{
			throw invalid_argument("you cant fly to the current city");
		}
		
		if (cards.at(current_city))
		{
			cards.at(current_city) = false;
			current_city = city;
		}

		else
		{
			throw invalid_argument("You don't have the card of this city");
		}
		return *this;
	}

	Player& Player::fly_shuttle(City city)
	{
		if (city == current_city)
		{
			throw invalid_argument("you cant fly to the current city");
		}
		
		if (board.researchFacility.at(current_city))
		{
			if (board.researchFacility.at(city))
			{
				current_city = city;
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

	Player& Player::build()
	{
		if (!board.researchFacility.at(current_city))
		{
			if (cards.at(current_city))
			{
				board.researchFacility.at(current_city) = true;
				cards.at(current_city) = false;
			}
			else
			{
				throw invalid_argument("You don't have a card of your current 				city");
			}

		}

		return *this;
	}

	Player& Player::discover_cure(Color color)
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
			if (board.researchFacility.at(current_city))
			{
				if (counter >= numbers_of_cards)
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
					throw invalid_argument("You dont have enough cards 						with the right color you need 5 cards");
				}
			}

			else
			{
				throw invalid_argument("There is no research facility in this 				city");
			}

		}

		return *this;
	}

	Player& Player::treat(City city)
	{
		if (current_city == city)
		{
			if (board.cubs.at(city) != 0)
			{
				unsigned int color_of_current_city = city / CITIES_PER_COLOR;

				if (board.cure.at(color_of_current_city))
				{
					board.cubs.at(city) = 0;
				}

				else
				{
					board.cubs.at(city) = board.cubs.at(city) - 1;
				}
			}

			else
			{
				throw invalid_argument("There is no infection in this city");
			}
		}

		else
		{
			throw invalid_argument("this is not your current city");
		}

		return *this;
	}

	string Player::role()
	{
		return "unemployed";
	}

	Player& Player::take_card(City city)
	{
		if (!cards.at(city))
		{
			cards.at(city) = true;
		}

		return *this;
	}

}

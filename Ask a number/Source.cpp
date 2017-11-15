#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int range_min;
	int range_max;
	int random;
	int num = 0;
	char again;
	std::string high_low_correct;
	
	
	do
	{
		std::cout << "Guess a number in your head.\n";

		Sleep(3000);

		std::cout << "Give me a range that i can work with(minimum and maximum): ";
		std::cin >> range_min >> range_max;

		srand(time(NULL));

		while (high_low_correct != "correct")
		{
			
			random = rand() % range_max + range_min;

			std::cout << "Is " << random << " high, low or correct: ";
			std::getline(std::cin, high_low_correct);

			if (high_low_correct == "high")
			{
				range_max = random--;
			}

			if (high_low_correct == "low")
			{
				range_min = random++;
			}
		}
		high_low_correct = "random";
		std::cout << "Wanna play again?(Y/N): ";
		std::cin >> again;
	} while (again == 'Y' || again == 'y');

	std::cin.get();
}
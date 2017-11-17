#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	char again = '[';

	do
	{
		int range_min;
		int range_max;
		int random;
		int counter = 0;
		std::string high_low_correct;

		std::cout << "Guess a number in your head...\n";

		Sleep(3000);

		std::cout << "Give me a range that i can work with(minimum and maximum): ";
		std::cin >> range_min >> range_max;

		while (range_min >= range_max)
		{
			std::cout << "Error!\nWrong range!\nPleas enter a valid range: ";
			std::cin >> range_min >> range_max;
		}
		

		while (high_low_correct != "correct")
		{
			srand(time(NULL));
			random = rand() % (range_max-range_min) + range_min;

			std::cout << "Is " << random << " higher, lower or your number(higher, lower, correct): ";
			std::cin >> high_low_correct;

			if (high_low_correct == "higher")
			{
				if (range_max - range_min == 1)
				{
					random++;
					high_low_correct = "correct";
				}

				random -= 1;
				range_max = random;
				counter++;
			}

			if (high_low_correct == "lower")
			{
				if (range_max - range_min == 1)
					high_low_correct = "correct";

				random += 1;
				range_min = random;
				counter++;
			}

			if (range_max - range_min == 0 || high_low_correct == "correct")
			{
				std::cout << "Your number is " << random << "!\n";
				std::cout << "Number of atempts: " << counter << "\n";
				high_low_correct = "correct";
			}
				
		}

		std::cout << "Wanna play again ? (Y / N) : ";
		std::cin >> again;

		system("cls");

	} while (again == 'Y' || again == 'y');

	std::cin.get();
}
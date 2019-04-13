#include <iostream>
#include <string>

bool boolPrompt(std::string message);

int intPrompt(std::string message);

int main()
{
	std::cout << "Welcome to the Ray Optics Test!\n";

	do
	{
		int numProblems = intPrompt("How many problems would"
				" you like to generate?");
		for (int i = 0; i < numProblems; i++)
			std::cout << i << std::endl;
	} while (boolPrompt("Would you like another problem set?"));

	return 0;
}

bool boolPrompt(std::string message)
{
	bool validInput = false;
	char initial = 0;
	while(!validInput)
	{
		std::cout << message << " (y/n): ";

		std::string input = "";
		std::getline(std::cin, input);
		initial = tolower(input[0]);

		if (initial == 'y' || initial == 'n')
			validInput = true;
		else
			std::cout << "Invalid input!"
				" Type \"yes\" or \"no\".\n";
	}

	return initial == 'y';
}

int intPrompt(std::string message)
{
	bool validInput = false;
	int value = 0;
	while(!validInput)
	{
		std::cout << message << " ";

		std::string input = "";
		std::getline(std::cin, input);
		char initial = input[0];

		if (initial >= '0' && initial <= '9')
		{
			validInput = true;
			value = std::stoi(input);
		}
		else
			std::cout << "Invalid input!"
				" Type a non-negative integer.\n";
	}

	return value;
}

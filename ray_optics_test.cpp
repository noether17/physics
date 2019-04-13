#include <iostream>
#include <string>

bool bPrompt(std::string message);

int main()
{
	do
	{

	} while (bPrompt("Would you like another problem set?"));

	return 0;
}

bool bPrompt(std::string message)
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

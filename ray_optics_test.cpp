#include <iostream>
#include <string>
#include <random>

std::string trim_white_space(std::string str);

bool bool_prompt(std::string message);

int int_prompt(std::string message);

void set_params(bool& mirrors, bool& lenses, int& n_probs);

int random_digit();

int generate_problem(bool mirrors, bool lenses);

int main()
{
	std::cout << "Welcome to the Ray Optics Test!\n";

	do
	{
		bool mirrors = false;
		bool lenses = false;
		int num_problems = 0;
		set_params(mirrors, lenses, num_problems);
		
		for (int i = 0; i < num_problems; i++)
			std::cout << i << '\t'
				<< mirrors << '\t'
				<< lenses << '\t' 
				<< generate_problem(mirrors, lenses) 
				<< std::endl;
	} while (bool_prompt("Would you like another problem set?"));

	return 0;
}

std::string trim_white_space(std::string str)
{
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return i ? str.erase(0, i) : str;
}

bool bool_prompt(std::string message)
{
	bool validInput = false;
	char initial = 0;
	while(!validInput)
	{
		std::cout << message << " (y/n): ";

		std::string input = "";
		std::getline(std::cin, input);
		input = trim_white_space(input);
		initial = tolower(input[0]);

		if (initial == 'y' || initial == 'n')
			validInput = true;
		else
			std::cout << "Invalid input!"
				" Type \"yes\" or \"no\".\n";
	}

	return initial == 'y';
}

int int_prompt(std::string message)
{
	bool validInput = false;
	int value = 0;
	while(!validInput)
	{
		std::cout << message << " ";

		std::string input = "";
		std::getline(std::cin, input);
		input = trim_white_space(input);
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

void set_params(bool& mirrors, bool& lenses, int& n_probs)
{
	mirrors = bool_prompt("Would you like to include"
			" problems with mirrors?");
	lenses = bool_prompt("Would you like to include"
			" problems with lenses?");
	if (!(mirrors || lenses))
	{
		std::cout << "Can't generate problem set!"
			<< " Must select at least one option."
			<< std::endl;
		set_params(mirrors, lenses, n_probs);
	}
	else
		n_probs = int_prompt("How many problems would"
				" you like to generate?");
}

int random_digit()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<> dis(0, 9);
	return dis(generator);
}

int generate_problem(bool mirrors, bool lenses)
{
	return random_digit();
}

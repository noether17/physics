#include <random>
#include <iostream>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	for (int i = 0; i < 20; ++i)
		std::cout << dis(gen) << std::endl;

	return 0;
}

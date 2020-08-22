#include <iostream>
#include <random>
#include <conio.h>

int main(void)
{
	int level = 1;
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 2);
	for (int i = 0; i < 100; i++)
		std::cout << dis(gen) << std::endl;
	_getch();

	std::uniform_int_distribution<int> dis2(0, 4);
	for (int i = 0; i < 100; i++)
		std::cout << dis2(gen) << std::endl;
	_getch();

	std::uniform_int_distribution<int> dis3(0, 5);
	for (int i = 0; i < 100; i++)
		std::cout << dis3(gen) << std::endl;

	return 0;
}
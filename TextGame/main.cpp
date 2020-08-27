/*프로그래밍이 비로소 나를 특별하게 한다.*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>
#include "TextHeader.h"


int main(void)
{
	GameStart();
	StandMenu();
	std::cout << "                   ";
	std::cout << "You Died" << std::endl;
	std::cout << "종료하려면 아무 키나 누르시오.";
	_getch();
}
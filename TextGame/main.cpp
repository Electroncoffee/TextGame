/*���α׷����� ��μ� ���� Ư���ϰ� �Ѵ�.*/
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
	std::cout << "�����Ϸ��� �ƹ� Ű�� �����ÿ�.";
	_getch();
}
/*프로그래밍이 비로소 나를 특별하게 한다.*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>
#include "TextHeader.h"
using namespace std;

int main(void)
{
	GameStart();
	StandMenu();
	cout << "                   ";
	cout << "You Died" << endl;
	cout << "종료하려면 아무 키나 누르시오.";
	_getch();
}
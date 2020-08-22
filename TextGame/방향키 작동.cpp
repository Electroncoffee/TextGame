#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>
using namespace std;
enum KEY { Ready = 224, Left = 75, Right = 77, Up = 72, Down = 80, Enter = 13, Space = 32, Zero = 48, One, Two, Three, Four, Five, Six, Seven, Eight, Nine };


int main(void)
{
	int key = 0;
	bool flag = true;
	bool i = false;
	while (1)
	{
		key = _getch();
		if (key != KEY::Ready)
			flag = false;
		if (key == KEY::Enter)
			break;
		if (flag)
		{
			key = _getch();
			if (key == KEY::Left)
				i = false;
			if (key == KEY::Right)
				i = true;
		}
		key = 0;
	}
	return 0;
}

/*
엔터if이전에 224체크하고 flag지정 flag만족시 두번째getch작동


#include <iostream>
#include <conio.h>
int main(void)
{
	std::cout << _getch() << std::endl;
	std::cout << _getch() << std::endl;
}
*/
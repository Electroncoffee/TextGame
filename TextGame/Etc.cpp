#include <iostream>
#include <conio.h>
#include "Etc.h"

void ETC::Middle(void) const
{ std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl; }

void ETC::PassKey(void)
{
	int key;
	std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != 13);
}
#include <iostream>
#include <conio.h>
#include "Etc.h"
using namespace std;

void ETC::Middle(void) const
{ cout << "\n\n\n\n\n\n\n\n\n\n"; }

void ETC::PassKey(void)
{
	int key;
	cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != 13);
}
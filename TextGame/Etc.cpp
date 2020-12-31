#include <iostream>
#include <conio.h>
#include "Etc.h"
using namespace std;

void ETC::Middle(void) const
{ cout << "\n\n\n\n\n\n\n\n\n\n"; }

void ETC::PassKey(void)
{
	int key;
	cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != 13);
}
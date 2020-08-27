#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Bag.h"

enum Item
{
	Etype_WoodSword, //0
	Etype_IronSword,
	Etype_PriestSword,
	Etype_DragonSword,
	Ctype_HPpotion,
	Ctype_ATKpotion
};

void Bag::Root(int icode) { own[icode]++; } //아이템 루팅
	
int Bag::ShowBag(void) //가방 보여주기
{
	system("cls");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	if (own[Item::Etype_WoodSword] != 0)
		std::cout << "0.목제검: " << own[Item::Etype_WoodSword] << "개" << std::endl;
	if (own[Item::Etype_IronSword] != 0)
		std::cout << "1.철제검: " << own[Item::Etype_IronSword] << "개" << std::endl;
	if (own[Item::Etype_PriestSword] != 0)
		std::cout << "2.제사장의검: " << own[Item::Etype_PriestSword] << "개" << std::endl;
	if (own[Item::Etype_DragonSword] != 0)
		std::cout << "3.용검: " << own[Item::Etype_DragonSword] << "개" << std::endl;
	std::cout << "4.체력포션: " << own[Item::Ctype_HPpotion] << "개" << std::endl;
	std::cout << "5.힘포션: " << own[Item::Ctype_ATKpotion] << "개" << std::endl << std::endl << std::endl;
	std::cout << "장비 장착은 숫자를, 뒤로가려면 엔터키를 누르시오";
	while (1)
	{
		key = _getch();
		if (key == 13)
			return -1;
		if (48 <= key && key <= 53)
		{
			key -= 48;
			if (own[key] > 0)
				own[key]--;
			return key;
		}

	}
}
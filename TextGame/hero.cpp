#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "hero.h"

	int character::Check_HP(void) { return hp; }
	int character::Check_level(void) { return level; }
	void character::Add_Exp(int drop_exp) {
		exp += drop_exp;
		if (exp >= Level_Up_Exp[level - 1])
		{
			exp -= Level_Up_Exp[level - 1];
			level++;
			pow += 2;
			max_hp += 2;
			std::cout << "레벨이 상승했다!" << std::endl;
		}
	}
	int character::Attack(void) {
		std::cout << "당신의 공격!" << std::endl;
		return pow;
	}
	int character::Damage(int damage)
	{
		std::cout << "당신은(는)" << damage << "의 피해를 입었다!" << std::endl;
		hp -= damage;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
	void character::Rest(void) {// 체력회복
		hp = max_hp;
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "체력이 회복되었다." << std::endl;
		int key;
		std::cout << "넘어가려면 엔터키를 누르시오";
		do
		{
			key = _getch();
		} while (key != 13);
		system("cls");
	}
	void character::Root(int icode) { MyBag.Root(icode); } //아이템 루팅
	void character::UseItem(void) //아이템 사용
	{
		int Item = MyBag.ShowBag();
		if (Item == -1)
			return;
		if (0 <= Item && Item <= 3) //장비교환
		{
			pow -= Item_Status[weapon];
			MyBag.Root(weapon);
			weapon = Item;
			pow += Item_Status[weapon];
		}
		if (Item == 4) //체력포션 사용
			max_hp += Item_Status[Item];
		if (Item == 5) //힘포션 사용
			pow += Item_Status[Item];
	}
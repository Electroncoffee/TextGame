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
			std::cout << "������ ����ߴ�!" << std::endl;
		}
	}
	int character::Attack(void) {
		std::cout << "����� ����!" << std::endl;
		return pow;
	}
	int character::Damage(int damage)
	{
		std::cout << "�����(��)" << damage << "�� ���ظ� �Ծ���!" << std::endl;
		hp -= damage;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
	void character::Rest(void) {// ü��ȸ��
		hp = max_hp;
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "ü���� ȸ���Ǿ���." << std::endl;
		int key;
		std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
		do
		{
			key = _getch();
		} while (key != 13);
		system("cls");
	}
	void character::Root(int icode) { MyBag.Root(icode); } //������ ����
	void character::UseItem(void) //������ ���
	{
		int Item = MyBag.ShowBag();
		if (Item == -1)
			return;
		if (0 <= Item && Item <= 3) //���ȯ
		{
			pow -= Item_Status[weapon];
			MyBag.Root(weapon);
			weapon = Item;
			pow += Item_Status[weapon];
		}
		if (Item == 4) //ü������ ���
			max_hp += Item_Status[Item];
		if (Item == 5) //������ ���
			pow += Item_Status[Item];
	}
#pragma once
#ifndef __HERO_H__
#define __HERO_H__
#include "Bag.h"

class character //���ΰ�
{
private:
	int Item_Status[6] = { 5,10,18,20,3,1 };
	int Level_Up_Exp[10] = { 10,30,60,90,130,180,240,310,390,490 };
	int key = 0;
	int level = 1;
	int exp = 0;
	int max_hp = 10;
	int hp = 10;
	int pow = 5;
	int weapon = 0;
	Bag MyBag;
public:
	char Item_Name[6][20] = { "������","ö����","�������ǰ�","���","ü������","������" };
	int Check_HP(void);
	int Check_level(void);
	void Add_Exp(int drop_exp);
	int Attack(void);
	int Damage(int damage);
	void ShowChar(void) const //const �Լ��� ������� ����,����
	{
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "����: " << level << std::endl;
		std::cout << "����ġ: " << exp << std::endl;
		std::cout << "�ִ�ü��: " << max_hp << std::endl;
		std::cout << "����ü��: " << hp << std::endl;
		std::cout << "���: " << Item_Name[weapon] << std::endl;
		std::cout << "���ݷ�: " << pow << std::endl << std::endl << std::endl;
		std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
	}
	void Rest(void);
	void Root(int icode);//������ ����
	void UseItem(void); //������ ���
};
#endif // !__HERO_H__

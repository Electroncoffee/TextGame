#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "Battle.h"

int AllAction::Battle(Battle_Monster &Monster, character &Hero)
{// ���� ����� 1, �÷��̾� ����� 0 ��ȯ
	system("cls");
	while (1)
	{	//�������� ������ ����ϸ� 1�� ��ȯ if���� �����
		if (Monster.Damage(Hero.Attack())) {
			flag = 1;
			std::cout << "������ �¸��ߴ�." << std::endl;
			std::cout << "����ġ�� " << Monster.Check_Exp() << "ȹ���ߴ�!" << std::endl;
			Hero.Add_Exp(Monster.Check_Exp());
			break;
		}
		if (Hero.Damage(Monster.Attack())) {
			flag = 0;
			std::cout << "������ �й��ߴ�." << std::endl;
			break;
		}
	}
	int key;
	std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}

void AllAction::Action(character &Hero) //Ž�� â(�������� �������� ����)
{
	Battle_Monster BMonster;
	level = Hero.Check_level();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> quest(1, 100); //����35% ����65%
	int flag = quest(gen);
	if (1 <= flag && flag <= 35)
	{
		Hero.Root(Item_Drop(6, Hero));
		return;
	}
	else {
		if (level <= 2)
		{
			std::uniform_int_distribution<int> dis(0, 2);
			BMonster.Init_Monster(dis(gen));
		}
		if (3 <= level && level <= 5)
		{
			std::uniform_int_distribution<int> dis(0, 4);
			BMonster.Init_Monster(dis(gen));
		}
		if (6 <= level)
		{
			std::uniform_int_distribution<int> dis(0, 5);
			BMonster.Init_Monster(dis(gen));
		}
	}
	if (Battle(BMonster, Hero)) {// ���� ����� 1, �÷��̾� ����� 0 ��ȯ
		Hero.Root(Item_Drop(BMonster.Check_Mcode(), Hero));
	}
}

int AllAction::Item_Drop(int code, character &Hero)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> drop(1, 100);
	int flag;
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	switch (code) {
	case 0: case 1: case 2: {
		std::uniform_int_distribution<int> dis1(0, 3);
		flag = dis1(gen);
		if (flag == 2)
			flag = 4;
		if (flag == 3)
			flag = 5;
		std::cout << "����ǰ���� ";
		break;
	}
	case 3: {
		flag = 5;
		std::cout << "����ǰ���� ";
		break;
	}
	case 4: {
		flag = 2;
		std::cout << "����ǰ���� ";
		break;
	}
	case 5: {
		flag = 3;
		std::cout << "���� óġ�ϰ� ";
		break;
	}
	case 6: {
		std::uniform_int_distribution<int> dis5(0, 3);
		flag = dis5(gen);
		if (flag == 2)
			flag = 4;
		if (flag == 3)
			flag = 5;
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "������ ���ڿ��� ";
		break;
	}
	}
	std::cout << Hero.Item_Name[flag] << "��(��)�߰��ߴ�." << std::endl;
	int key;
	std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}
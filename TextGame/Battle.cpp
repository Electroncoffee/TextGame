#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "Battle.h"
using namespace std;

int AllAction::Battle(Battle_Monster &Monster, character &Hero)
{// ���� ����� 1, �÷��̾� ����� 0 ��ȯ
	system("cls");
	while (1)
	{	//�������� ������ ����ϸ� 1�� ��ȯ if���� �����
		if (Monster.Damage(Hero.Attack())) {
			flag = 1;
			cout << "������ �¸��ߴ�." << endl;
			cout << "����ġ�� " << Monster.Check_Exp() << "ȹ���ߴ�!" << endl;
			Hero.Add_Exp(Monster.Check_Exp());
			break;
		}
		Sleep(1000);
		if (Hero.Damage(Monster.Attack())) {
			flag = 0;
			cout << "������ �й��ߴ�." << endl;
			break;
		}
		Sleep(1000);
	}
	int key;
	cout << "�Ѿ���� ����Ű�� �����ÿ�";
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
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> quest(1, 100); //����35% ����65%
	int flag = quest(gen);
	if (1 <= flag && flag <= 35)
	{
		Hero.Root(Item_Drop(6, Hero));
		return;
	}
	else {
		if (level <= 2)
		{
			uniform_int_distribution<int> dis(0, 2);
			BMonster.Init_Monster(dis(gen));
		}
		if (3 <= level && level <= 5)
		{
			uniform_int_distribution<int> dis(0, 4);
			BMonster.Init_Monster(dis(gen));
		}
		if (6 <= level)
		{
			uniform_int_distribution<int> dis(0, 5);
			BMonster.Init_Monster(dis(gen));
		}
	}
	if (Battle(BMonster, Hero)) {// ���� ����� 1, �÷��̾� ����� 0 ��ȯ
		Hero.Root(Item_Drop(BMonster.Check_Mcode(), Hero));
	}
}

int AllAction::Item_Drop(int code, character &Hero)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> drop(1, 100);
	int flag;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	switch (code) {
	case 0: case 1: case 2: {
		uniform_int_distribution<int> dis1(0, 3);
		flag = dis1(gen);
		if (flag == 2)
			flag = 4;
		if (flag == 3)
			flag = 5;
		cout << "����ǰ���� ";
		break;
	}
	case 3: {
		flag = 5;
		cout << "����ǰ���� ";
		break;
	}
	case 4: {
		flag = 2;
		cout << "����ǰ���� ";
		break;
	}
	case 5: {
		flag = 3;
		cout << "���� óġ�ϰ� ";
		break;
	}
	case 6: {
		uniform_int_distribution<int> dis5(0, 3);
		flag = dis5(gen);
		if (flag == 2)
			flag = 4;
		if (flag == 3)
			flag = 5;
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "������ ���ڿ��� ";
		break;
	}
	}
	cout << Hero.Item_Name[flag] << "��(��)�߰��ߴ�." << endl;
	int key;
	cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}
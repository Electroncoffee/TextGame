#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "Battle.h"
using namespace std;

int AllAction::Battle(Battle_Monster &Monster, character &Hero)
{// 몬스터 사망시 1, 플레이어 사망시 0 반환
	system("cls");
	while (1)
	{	//데미지를 받을때 사망하면 1을 반환 if문이 실행됨
		if (Monster.Damage(Hero.Attack())) {
			flag = 1;
			cout << "전투에 승리했다." << endl;
			cout << "경험치를 " << Monster.Check_Exp() << "획득했다!" << endl;
			Hero.Add_Exp(Monster.Check_Exp());
			break;
		}
		Sleep(1000);
		if (Hero.Damage(Monster.Attack())) {
			flag = 0;
			cout << "전투에 패배했다." << endl;
			break;
		}
		Sleep(1000);
	}
	int key;
	cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}

void AllAction::Action(character &Hero) //탐색 창(몬스터인지 상자인지 구분)
{
	Battle_Monster BMonster;
	level = Hero.Check_level();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> quest(1, 100); //상자35% 몬스터65%
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
	if (Battle(BMonster, Hero)) {// 몬스터 사망시 1, 플레이어 사망시 0 반환
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
		cout << "전리품으로 ";
		break;
	}
	case 3: {
		flag = 5;
		cout << "전리품으로 ";
		break;
	}
	case 4: {
		flag = 2;
		cout << "전리품으로 ";
		break;
	}
	case 5: {
		flag = 3;
		cout << "용을 처치하고 ";
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
		cout << "숲속의 상자에서 ";
		break;
	}
	}
	cout << Hero.Item_Name[flag] << "을(를)발견했다." << endl;
	int key;
	cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}
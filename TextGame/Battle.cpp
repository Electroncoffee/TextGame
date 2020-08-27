#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "Battle.h"

int AllAction::Battle(Battle_Monster &Monster, character &Hero)
{// 몬스터 사망시 1, 플레이어 사망시 0 반환
	system("cls");
	while (1)
	{	//데미지를 받을때 사망하면 1을 반환 if문이 실행됨
		if (Monster.Damage(Hero.Attack())) {
			flag = 1;
			std::cout << "전투에 승리했다." << std::endl;
			std::cout << "경험치를 " << Monster.Check_Exp() << "획득했다!" << std::endl;
			Hero.Add_Exp(Monster.Check_Exp());
			break;
		}
		if (Hero.Damage(Monster.Attack())) {
			flag = 0;
			std::cout << "전투에 패배했다." << std::endl;
			break;
		}
	}
	int key;
	std::cout << "넘어가려면 엔터키를 누르시오";
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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> quest(1, 100); //상자35% 몬스터65%
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
	if (Battle(BMonster, Hero)) {// 몬스터 사망시 1, 플레이어 사망시 0 반환
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
		std::cout << "전리품으로 ";
		break;
	}
	case 3: {
		flag = 5;
		std::cout << "전리품으로 ";
		break;
	}
	case 4: {
		flag = 2;
		std::cout << "전리품으로 ";
		break;
	}
	case 5: {
		flag = 3;
		std::cout << "용을 처치하고 ";
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
		std::cout << "숲속의 상자에서 ";
		break;
	}
	}
	std::cout << Hero.Item_Name[flag] << "을(를)발견했다." << std::endl;
	int key;
	std::cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != 13);
	return flag;
}
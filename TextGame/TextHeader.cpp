#include <iostream>
#include <conio.h>
#include "TextHeader.h"
#include "hero.h"
#include "Battle.h"

AllAction allaction;

void Tutorial(void)
{
	system("cls");
	std::cout << "튜토리얼 들어갈 곳" << std::endl;
	int key;
	std::cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != 13);
}

void GameStart(void)
{
	int key;
	bool i = false;
	while (1)
	{
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "                                                    ";
		std::cout << "Text Game";
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "                         ";
		std::cout << "게임시작";
		std::cout << "                                         ";
		std::cout << "게임방법" << std::endl;
		if (i == 0)
		{
			std::cout << "                         ";
			std::cout << "--------";
		}
		if (i == 1)
		{
			std::cout << "                                                                          ";
			std::cout << "--------";
		}
		key = _getch();
		if (key == 13)
			break;
		if (key != 224)
			continue;
		key = _getch();
		if (key == 75)
			i = false;
		if (key == 77)
			i = true;
		key = 0;
		
	}
	if (i == true)
		Tutorial();
}

void StandMenu(void)//행동선택 창
{
	character Hero;
	int key;
	char i = 0;
	while (Hero.Check_HP() > 0)
	{
		while (1)
		{
			system("cls");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "                                                       ";
			std::cout << "행동 선택";
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "                 ";
			std::cout << "(1)장비사용              (2)캐릭터상태              (3)휴식              (4)탐색" << std::endl;
			switch (i)
			{
			case 0:
				std::cout << "                 ";
				std::cout << "-----------";
				break;
			case 1:
				std::cout << "                                          ";
				std::cout << "-------------";
				break;
			case 2:
				std::cout << "                                                                     ";
				std::cout << "-------";
				break;
			case 3:
				std::cout << "                                                                                          ";
				std::cout << "-------";
				break;
			}
			key = _getch();
			if (key == 13)
				break;
			if (key != 224)
				continue;
			key = _getch();
			if (key == 75)
			{
				if (i > 0)
					i--;
			}
			if (key == 77)
			{
				if (i < 3)
					i++;
			}
			key = 0;
		}
		switch (i)
		{
		case 0:
			Hero.UseItem();
			break;
		case 1:
			Hero.ShowChar();
			std::cout << "넘어가려면 엔터키를 누르시오";
			do
			{
				key = _getch();
			} while (key != 13);
			break;
		case 2:
			Hero.Rest();
			break;
		case 3:
			allaction.Action(Hero);
			break;
		}
	}
}
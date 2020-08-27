#include <iostream>
#include <conio.h>
#include "TextHeader.h"
#include "hero.h"
#include "Battle.h"

AllAction allaction;

void Tutorial(void)
{
	system("cls");
	std::cout << "Ʃ�丮�� �� ��" << std::endl;
	int key;
	std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
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
		std::cout << "���ӽ���";
		std::cout << "                                         ";
		std::cout << "���ӹ��" << std::endl;
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

void StandMenu(void)//�ൿ���� â
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
			std::cout << "�ൿ ����";
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "                 ";
			std::cout << "(1)�����              (2)ĳ���ͻ���              (3)�޽�              (4)Ž��" << std::endl;
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
			std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
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
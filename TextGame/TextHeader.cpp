#include <iostream>
#include <conio.h>
#include "TextHeader.h"
#include "hero.h"
#include "Battle.h"
using namespace std;
AllAction allaction;

void Tutorial(void)
{
	system("cls");
	cout << "Ʃ�丮�� �� ��" << endl;
	int key;
	cout << "�Ѿ���� ����Ű�� �����ÿ�";
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
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "                                                    ";
		cout << "Text Game";
		cout << "\n\n\n\n\n\n\n\n";
		cout << "                         ";
		cout << "���ӽ���";
		cout << "                                         ";
		cout << "���ӹ��" << endl;
		if (i == 0)
		{
			cout << "                         ";
			cout << "--------";
		}
		if (i == 1)
		{
			cout << "                                                                          ";
			cout << "--------";
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
			cout << "\n\n\n\n\n\n\n\n\n\n";
			cout << "                                                       ";
			cout << "�ൿ ����";
			cout << "\n\n\n\n";
			cout << "                 ";
			cout << "(1)�����              (2)ĳ���ͻ���              (3)�޽�              (4)Ž��" << endl;
			switch (i)
			{
			case 0:
				cout << "                 ";
				cout << "-----------";
				break;
			case 1:
				cout << "                                          ";
				cout << "-------------";
				break;
			case 2:
				cout << "                                                                     ";
				cout << "-------";
				break;
			case 3:
				cout << "                                                                                          ";
				cout << "-------";
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
			cout << "�Ѿ���� ����Ű�� �����ÿ�";
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
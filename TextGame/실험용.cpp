#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>

char key = 0;
void Initkey(void) { key = 0; }
void Middle(void);
void Tutorial(void);
void GameStart(void);
void Action(void);
char Item_Name[6][20] = { "������","ö����","�������ǰ�","���","ü������","������" };
char Monster_Name[6][20] = { "����","����","�ŵ�","����","������","��" };
int Item_Status[6] = { 5,10,18,20,5,5 };
char Monster_Status[6][3] = { {4,1,5},{7,2,10},{10,4,15},{12,5,25},{20,10,40},{30,15,60} }; //hp,pow,exp
//int exp[10] = {10,30,60,90,130,180,240,310,390,490};
enum KEY { Left = 75, Right = 77, Up = 72, Down = 80, Enter = 13, Space = 32, Zero = 48, One, Two, Three, Four, Five, Six, Seven, Eight, Nine };
enum Item
{
	Etype_WoodSword, //0
	Etype_IronSword,
	Etype_PriestSword,
	Etype_DragonSword,
	Ctype_HPpotion,
	Ctype_ATKpotion
};
enum Monster
{
	Mon_Bat, //0
	Mon_Wolf,
	Mon_devotee,
	Mon_DragonKnight,
	Mon_Priest,
	Mon_Dragon
};

class Battle_Monster
{
private:
	int hp, pow, drop_exp;
	int Monster_code;
public:
	Battle_Monster(int hp, int pow, int drop_exp,int code)
		:hp(hp), pow(pow), drop_exp(drop_exp) {}
	int Attack(void) { return pow; }
	int Damage(int damage)
	{
		hp -= pow;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
};

class Bag //�賶
{
private:
	int own[6] = { 1,1,1,1,1,1 };
public:
	void Root(int icode) { own[icode]++; } //������ ����
	int ShowBag(void) //���� �����ֱ�
	{
		system("cls");
		Middle();
		if (own[Item::Etype_WoodSword] != 0)
			std::cout << "0.������: " << own[Item::Etype_WoodSword] << "��" << std::endl;
		if (own[Item::Etype_IronSword] != 0)
			std::cout << "1.ö����: " << own[Item::Etype_IronSword] << "��" << std::endl;
		if (own[Item::Etype_PriestSword] != 0)
			std::cout << "2.�������ǰ�: " << own[Item::Etype_PriestSword] << "��" << std::endl;
		if (own[Item::Etype_DragonSword] != 0)
			std::cout << "3.���: " << own[Item::Etype_DragonSword] << "��" << std::endl;
		std::cout << "4.ü������: " << own[Item::Ctype_HPpotion] << "��" << std::endl;
		std::cout << "5.������: " << own[Item::Ctype_ATKpotion] << "��" << std::endl << std::endl << std::endl;
		std::cout << "��� ������ ���ڸ�, �ڷΰ����� ����Ű�� �����ÿ�";
		while (1)
		{
			key = _getch();
			if (key == KEY::Enter)
				return -1;
			if (KEY::Zero <= key && key <= KEY::Five)
			{
				key -= 48;
				if (own[key] > 0)
					own[key]--;
				return key;
			}

		}
	}
};

class character //���ΰ�
{
private:
	int level = 1;
	int exp = 0;
	int max_hp = 10;
	int hp = 10;
	int pow = 5;
	int weapon = 0;
	Bag MyBag;
public:
	int Attack(void) { return pow; }
	int Damage(int damage)
	{
		hp -= pow;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
	void ShowChar(void) const //���� ����
	{
		Middle();
		std::cout << "�ִ�ü��: " << max_hp << std::endl;
		std::cout << "����ü��: " << hp << std::endl;
		std::cout << "���: " << Item_Name[weapon] << std::endl;
		std::cout << "���ݷ�: " << pow << std::endl << std::endl << std::endl;
		std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
		do
		{
			key = _getch();
		} while (key != KEY::Enter);
	}
	void ShowBag(void) { MyBag.ShowBag(); }
	void Rest(void) { hp = max_hp; } //�޽�
	void Root(int icode) { MyBag.Root(icode); } //������ ����
	int Check_HP(void) const { return hp; } //ü�� üũ
	void UseItem(void)
	{
		int Item = MyBag.ShowBag();
		if (Item == -1)
			return;
		if (0 <= Item && Item <= 3)
		{
			pow -= Item_Status[weapon];
			MyBag.Root(weapon);
			weapon = Item;
			pow += Item_Status[weapon];
		}
		if (Item == 4)
			max_hp += Item_Status[Item];
		if (Item == 5)
			pow += Item_Status[Item];
	}
};

void Action(character &Hero)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<int> dis(1, 5);

}

void Middle(void) { std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl; }

void Tutorial(void)
{
	system("cls");
	std::cout << "Ʃ�丮�� �� ��" << std::endl;
}

void GameStart(void)
{
	bool i = false;
	while (1)
	{
		Middle();
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
		if (key == KEY::Enter)
			break;
		key = _getch();
		if (key == KEY::Left)
			i = false;
		else if (key == KEY::Right)
			i = true;
		system("cls");
	}
	if (i == true)
		Tutorial();
}

void StandMenu(character &Hero)
{
	char i = 0;
	while (Hero.Check_HP() > 0)
	{
		while (1)
		{
			system("cls");
			Middle();
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
			if (key == KEY::Enter)
				break;
			key = _getch();
			if (key == KEY::Left)
			{
				if (i > 0)
					i--;
			}
			if (key == KEY::Right)
			{
				if (i < 3)
					i++;
			}
		}
		switch (i)
		{
		case 0:
			Hero.UseItem();
			break;
		case 1:
			Hero.ShowChar();
			break;
		case 2:
			Hero.Rest();
			break;
		case 3:
			Action(Hero);
			break;
		}
	}
}
int main(void)
{
	character Hero;
	GameStart();
	StandMenu(Hero);
}
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>

int key = 0;
void Initkey(void) { key = 0; }
enum KEY { Ready = 224, Left = 75, Right = 77, Up = 72, Down = 80, Enter = 13, Space = 32, Zero = 48, One, Two, Three, Four, Five, Six, Seven, Eight, Nine };
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
void Middle(void);
void PassKey(void)
{
	std::cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do
	{
		key = _getch();
	} while (key != KEY::Enter);
}
void Tutorial(void);
void GameStart(void);
char Item_Name[6][20] = { "������","ö����","�������ǰ�","���","ü������","������" };
char Monster_Name[6][20] = { "����","����","�ŵ�","����","������","��" };
int Item_Status[6] = { 5,10,18,20,5,5 };
char Monster_Status[6][3] = { {4,1,5},{7,2,10},{10,4,15},{12,5,25},{20,10,40},{30,15,60} }; //hp,pow,exp
//int exp[10] = {10,30,60,90,130,180,240,310,390,490};

class Battle_Monster
{
private:
	int hp, pow;
	int Monster_code;
public:
	/*
	//���� ������ �ʱ�ȭ ��Ű�� ������
	Battle_Monster(int code) : Monster_code(code)
	{
		hp = Monster_Status[code][0];
		pow = Monster_Status[code][1];
		drop_exp = Monster_Status[code][2];
	}
	*/
	void Init_Monster(int code)
	{
		hp = Monster_Status[code][0];
		pow = Monster_Status[code][1];
		Monster_code = code;
	}
	int Check_HP(void) { return hp; }
	int Check_Mcode(void) const { return Monster_code; }
	int Attack(void) {
		std::cout << Monster_Name[Monster_code] << "�� ����!" <<std::endl;
		return pow;
	}
	int Damage(int damage)
	{
		std::cout << Monster_Name[Monster_code] << "��(��)" << damage << "�� ���ظ� �Ծ���!" << std::endl;
		hp -= damage;
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
	int Check_HP(void) { return hp; }
	int Check_level(void) { return level; }
	int Attack(void) {
		std::cout << "����� ����!" << std::endl;
		return pow;
	}
	int Damage(int damage)
	{
		std::cout << "�����(��)" << damage << "�� ���ظ� �Ծ���!" << std::endl;
		hp -= damage;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
	void ShowChar(void) const //���� ����
	{
		system("cls");
		Middle();
		std::cout << "����: " << level << std::endl;
		std::cout << "����ġ: " << exp << std::endl;
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
	void Rest(void) {// ü��ȸ��
		hp = max_hp;
		system("cls");
		Middle();
		std::cout << "ü���� ȸ���Ǿ���." << std::endl;
		PassKey();
		system("cls");
	}
	void Root(int icode) { MyBag.Root(icode); } //������ ����
	void UseItem(void) //������ ���
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
};

int Item_Drop(int code)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> drop(1, 100);
	int flag;
	Middle();
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
	}
	case 6: {
		std::uniform_int_distribution<int> dis5(0, 3);
		flag = dis5(gen);
		if (flag == 2)
			flag = 4;
		if (flag == 3)
			flag = 5;
		system("cls");
		Middle();
		std::cout << "������ ���ڿ��� ";
		break;
	}
	}
	std::cout << Item_Name[flag] << "��(��)�߰��ߴ�." << std::endl;
	PassKey();
	return flag;
}

int Battle(Battle_Monster &Monster, character &Hero)
{// ���� ����� 1, �÷��̾� ����� 0 ��ȯ
	int flag;
	system("cls");
	while (1)
	{	//�������� ������ ����ϸ� 1�� ��ȯ if���� �����
		if (Monster.Damage(Hero.Attack())){
			flag = 1;
			std::cout << "������ �¸��ߴ�." << std::endl;
			break;
		}
		if (Hero.Damage(Monster.Attack())){
			flag = 0;
			std::cout << "������ �й��ߴ�." << std::endl;
			break;
		}
	}
	PassKey();
	return flag;
}

void Action(character &Hero) //Ž�� â(�������� �������� ����)
{
	Battle_Monster BMonster;
	int level = Hero.Check_level();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> quest(1,100); //����35% ����65%
	int flag = quest(gen);
	if (1<=flag && flag<= 35)
	{
		Hero.Root(Item_Drop(6));
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
		Hero.Root(Item_Drop(BMonster.Check_Mcode()));
	}
}

void Middle(void) { std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl; }

void Tutorial(void)
{
	system("cls");
	std::cout << "Ʃ�丮�� �� ��" << std::endl;
	PassKey();
}

void GameStart(void)
{
	bool i = false;
	while (1)
	{
		system("cls");
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
		if (key != KEY::Ready)
			continue;
		key = _getch();
		if (key == KEY::Left)
			i = false;
		if (key == KEY::Right)
			i = true;
		Initkey();
	}
	if (i == true)
		Tutorial();
}

void StandMenu(character &Hero) //�ൿ���� â
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
			if (key != KEY::Ready)
				continue;
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
			Initkey();
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
void GameOver(void)
{
	Middle();
	std::cout << "                   ";
	std::cout << "You Died" << std::endl;
	std::cout << "�����Ϸ��� �ƹ� Ű�� �����ÿ�.";
	_getch();
}
int main(void)
{
	character Hero;
	GameStart();
	StandMenu(Hero);
	GameOver();
}
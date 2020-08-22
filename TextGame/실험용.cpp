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
	std::cout << "넘어가려면 엔터키를 누르시오";
	do
	{
		key = _getch();
	} while (key != KEY::Enter);
}
void Tutorial(void);
void GameStart(void);
char Item_Name[6][20] = { "목제검","철제검","제사장의검","용검","체력포션","힘포션" };
char Monster_Name[6][20] = { "박쥐","늑대","신도","용기사","제사장","용" };
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
	//몬스터 정보를 초기화 시키는 생성자
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
		std::cout << Monster_Name[Monster_code] << "의 공격!" <<std::endl;
		return pow;
	}
	int Damage(int damage)
	{
		std::cout << Monster_Name[Monster_code] << "은(는)" << damage << "의 피해를 입었다!" << std::endl;
		hp -= damage;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
};

class Bag //배낭
{
private:
	int own[6] = { 1,1,1,1,1,1 };
public:
	void Root(int icode) { own[icode]++; } //아이템 루팅
	int ShowBag(void) //가방 보여주기
	{
		system("cls");
		Middle();
		if (own[Item::Etype_WoodSword] != 0)
			std::cout << "0.목제검: " << own[Item::Etype_WoodSword] << "개" << std::endl;
		if (own[Item::Etype_IronSword] != 0)
			std::cout << "1.철제검: " << own[Item::Etype_IronSword] << "개" << std::endl;
		if (own[Item::Etype_PriestSword] != 0)
			std::cout << "2.제사장의검: " << own[Item::Etype_PriestSword] << "개" << std::endl;
		if (own[Item::Etype_DragonSword] != 0)
			std::cout << "3.용검: " << own[Item::Etype_DragonSword] << "개" << std::endl;
		std::cout << "4.체력포션: " << own[Item::Ctype_HPpotion] << "개" << std::endl;
		std::cout << "5.힘포션: " << own[Item::Ctype_ATKpotion] << "개" << std::endl << std::endl << std::endl;
		std::cout << "장비 장착은 숫자를, 뒤로가려면 엔터키를 누르시오";
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

class character //주인공
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
		std::cout << "당신의 공격!" << std::endl;
		return pow;
	}
	int Damage(int damage)
	{
		std::cout << "당신은(는)" << damage << "의 피해를 입었다!" << std::endl;
		hp -= damage;
		if (hp > 0)
			return 0;
		else
			return 1;
	}
	void ShowChar(void) const //스탯 열람
	{
		system("cls");
		Middle();
		std::cout << "레벨: " << level << std::endl;
		std::cout << "경험치: " << exp << std::endl;
		std::cout << "최대체력: " << max_hp << std::endl;
		std::cout << "현재체력: " << hp << std::endl;
		std::cout << "장비: " << Item_Name[weapon] << std::endl;
		std::cout << "공격력: " << pow << std::endl << std::endl << std::endl;
		std::cout << "넘어가려면 엔터키를 누르시오";
		do
		{
			key = _getch();
		} while (key != KEY::Enter);
	}
	void Rest(void) {// 체력회복
		hp = max_hp;
		system("cls");
		Middle();
		std::cout << "체력이 회복되었다." << std::endl;
		PassKey();
		system("cls");
	}
	void Root(int icode) { MyBag.Root(icode); } //아이템 루팅
	void UseItem(void) //아이템 사용
	{
		int Item = MyBag.ShowBag();
		if (Item == -1)
			return;
		if (0 <= Item && Item <= 3) //장비교환
		{
			pow -= Item_Status[weapon];
			MyBag.Root(weapon);
			weapon = Item;
			pow += Item_Status[weapon];
		}
		if (Item == 4) //체력포션 사용
			max_hp += Item_Status[Item];
		if (Item == 5) //힘포션 사용
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
		std::cout << "숲속의 상자에서 ";
		break;
	}
	}
	std::cout << Item_Name[flag] << "을(를)발견했다." << std::endl;
	PassKey();
	return flag;
}

int Battle(Battle_Monster &Monster, character &Hero)
{// 몬스터 사망시 1, 플레이어 사망시 0 반환
	int flag;
	system("cls");
	while (1)
	{	//데미지를 받을때 사망하면 1을 반환 if문이 실행됨
		if (Monster.Damage(Hero.Attack())){
			flag = 1;
			std::cout << "전투에 승리했다." << std::endl;
			break;
		}
		if (Hero.Damage(Monster.Attack())){
			flag = 0;
			std::cout << "전투에 패배했다." << std::endl;
			break;
		}
	}
	PassKey();
	return flag;
}

void Action(character &Hero) //탐색 창(몬스터인지 상자인지 구분)
{
	Battle_Monster BMonster;
	int level = Hero.Check_level();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> quest(1,100); //상자35% 몬스터65%
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
	if (Battle(BMonster, Hero)) {// 몬스터 사망시 1, 플레이어 사망시 0 반환
		Hero.Root(Item_Drop(BMonster.Check_Mcode()));
	}
}

void Middle(void) { std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl; }

void Tutorial(void)
{
	system("cls");
	std::cout << "튜토리얼 들어갈 곳" << std::endl;
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

void StandMenu(character &Hero) //행동선택 창
{
	char i = 0;
	while (Hero.Check_HP() > 0)
	{
		while (1)
		{
			system("cls");
			Middle();
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
	std::cout << "종료하려면 아무 키나 누르시오.";
	_getch();
}
int main(void)
{
	character Hero;
	GameStart();
	StandMenu(Hero);
	GameOver();
}
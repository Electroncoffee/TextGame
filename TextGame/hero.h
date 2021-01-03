#pragma once
#ifndef __HERO_H__
#define __HERO_H__
#include "Bag.h"
#define Maxexp 9999
using namespace std;

class character {//주인공
private:
	int Item_Status[6] = { 5,10,18,20,3,1 };
	int Level_Up_Exp[10] = { 10,30,60,90,130,180,240,310,390,490 };
	int key = 0;
	int level = 1;
	int exp = 0;
	int max_hp = 10;
	int hp = 10;
	int pow = 5;
	int weapon = 0;
	Bag MyBag;
public:
	char Item_Name[6][20] = { "목제검","철제검","제사장의검","용검","체력포션","힘포션" };
	int Check_HP(void);
	int Check_level(void);
	void Add_Exp(int drop_exp);
	int Attack(void);
	int Damage(int damage);
	void ShowChar(void) const { //const 함수라 헤더에서 선언,정의
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "레벨: " << level << endl;
		cout << "경험치: " << exp << endl;
		cout << "최대체력: " << max_hp << endl;
		cout << "현재체력: " << hp << endl;
		cout << "장비: " << Item_Name[weapon] << endl;
		cout << "공격력: " << pow << "\n\n" << endl;
	}
	void Rest(void);
	void Root(int icode);//아이템 루팅
	void UseItem(void); //아이템 사용
};
#endif // !__HERO_H__

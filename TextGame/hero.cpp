#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "hero.h"
using namespace std;

int character::Check_HP(void) { return hp; }
int character::Check_level(void) { return level; }
void character::Add_Exp(int drop_exp) {//경험치 획득
	exp += drop_exp;
	if (exp >= Level_Up_Exp[level - 1]) {//레벨업
		if (level==(sizeof(Level_Up_Exp)/4)+1) {//최고레벨이면
			return;
		}
		exp -= Level_Up_Exp[level - 1];
		level++;
		pow += 2;
		max_hp += 2;
		cout << "레벨이 상승했다!" << endl;
	}
}
int character::Attack(void) {
	cout << "당신의 공격!" << endl;
	return pow;
}
int character::Damage(int damage) {
	cout << "당신은(는)" << damage << "의 피해를 입었다!" << endl;
	hp -= damage;
	if (hp > 0)
		return 0;
	else
		return 1;
}
void character::Rest(void) {//체력회복
	hp = max_hp;
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "체력이 회복되었다." << endl;
	int key;
	cout << "넘어가려면 엔터키를 누르시오";
	do {
		key = _getch();
	} while (key != 13);
	system("cls");
}
void character::Root(int icode) { MyBag.Root(icode); }//아이템 루팅
void character::UseItem(void) {//아이템 사용
	int Item = MyBag.ShowBag();//가방 출력, 반환값은 -2~5까지
	switch (Item) {
	case -2://아이템 갯수 부족
		cout << "아이템이 없습니다." << endl;
		Sleep(1000);
		break;
	case -1://이전창으로 돌아가기
		return;
	case 0://무기 교체
	case 1:
	case 2:
	case 3:
		pow -= Item_Status[weapon];
		MyBag.Root(weapon);
		weapon = Item;
		pow += Item_Status[weapon];
		cout << "장착되었습니다." << endl;
		Sleep(1000);
		break;
	case 4://체력포션 사용
		max_hp += Item_Status[Item];
		cout << "최대체력이 증가합니다." << endl;
		Sleep(1000);
		break;
	case 5://힘포션 사용
		pow += Item_Status[Item];
		cout << "공격력이 증가합니다." << endl;
		Sleep(1000);
		break;
	}
}
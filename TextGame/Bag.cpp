#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Bag.h"
using namespace std;

enum Item {//열거형 상수로 아이템 넘버 정렬
	Etype_WoodSword, //0
	Etype_IronSword,
	Etype_PriestSword,
	Etype_DragonSword,
	Ctype_HPpotion,
	Ctype_ATKpotion
};
void Bag::Root(int icode) { own[icode]++; } //아이템 획득
int Bag::ShowBag(void) {//가방 보여주기
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	if (own[Item::Etype_WoodSword] != 0)
		cout << "0.목제검: " << own[Item::Etype_WoodSword] << "개" << endl;
	if (own[Item::Etype_IronSword] != 0)
		cout << "1.철제검: " << own[Item::Etype_IronSword] << "개" << endl;
	if (own[Item::Etype_PriestSword] != 0)
		cout << "2.제사장의검: " << own[Item::Etype_PriestSword] << "개" << endl;
	if (own[Item::Etype_DragonSword] != 0)
		cout << "3.용검: " << own[Item::Etype_DragonSword] << "개" << endl;
	cout << "4.체력포션: " << own[Item::Ctype_HPpotion] << "개" << endl;
	cout << "5.힘포션: " << own[Item::Ctype_ATKpotion] << "개" << endl << endl << endl;
	cout << "장비 장착은 숫자를, 뒤로가려면 엔터키를 누르시오";
	while (1) {//명령어 입력까지 무한반복
		key = _getch();
		if (key == 13) //엔터 입력
			return -1;
		if (48 <= key && key <= 53) {//0~5 입력
			key -= 48;
			if (own[key] > 0) {//장비가 있다면
				own[key]--; //가방에서 1개제거
			}
			else {//장비가 없다면
				key = -2;//-2를 반환
			}
			return key;
		}
	}
}
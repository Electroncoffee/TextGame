#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "hero.h"
using namespace std;

int character::Check_HP(void) { return hp; }
int character::Check_level(void) { return level; }
void character::Add_Exp(int drop_exp) {//����ġ ȹ��
	exp += drop_exp;
	if (exp >= Level_Up_Exp[level - 1]) {//������
		if (level==(sizeof(Level_Up_Exp)/4)+1) {//�ְ����̸�
			return;
		}
		exp -= Level_Up_Exp[level - 1];
		level++;
		pow += 2;
		max_hp += 2;
		cout << "������ ����ߴ�!" << endl;
	}
}
int character::Attack(void) {
	cout << "����� ����!" << endl;
	return pow;
}
int character::Damage(int damage) {
	cout << "�����(��)" << damage << "�� ���ظ� �Ծ���!" << endl;
	hp -= damage;
	if (hp > 0)
		return 0;
	else
		return 1;
}
void character::Rest(void) {//ü��ȸ��
	hp = max_hp;
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "ü���� ȸ���Ǿ���." << endl;
	int key;
	cout << "�Ѿ���� ����Ű�� �����ÿ�";
	do {
		key = _getch();
	} while (key != 13);
	system("cls");
}
void character::Root(int icode) { MyBag.Root(icode); }//������ ����
void character::UseItem(void) {//������ ���
	int Item = MyBag.ShowBag();//���� ���, ��ȯ���� -2~5����
	switch (Item) {
	case -2://������ ���� ����
		cout << "�������� �����ϴ�." << endl;
		Sleep(1000);
		break;
	case -1://����â���� ���ư���
		return;
	case 0://���� ��ü
	case 1:
	case 2:
	case 3:
		pow -= Item_Status[weapon];
		MyBag.Root(weapon);
		weapon = Item;
		pow += Item_Status[weapon];
		cout << "�����Ǿ����ϴ�." << endl;
		Sleep(1000);
		break;
	case 4://ü������ ���
		max_hp += Item_Status[Item];
		cout << "�ִ�ü���� �����մϴ�." << endl;
		Sleep(1000);
		break;
	case 5://������ ���
		pow += Item_Status[Item];
		cout << "���ݷ��� �����մϴ�." << endl;
		Sleep(1000);
		break;
	}
}
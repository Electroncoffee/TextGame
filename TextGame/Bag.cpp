#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Bag.h"
using namespace std;

enum Item {//������ ����� ������ �ѹ� ����
	Etype_WoodSword, //0
	Etype_IronSword,
	Etype_PriestSword,
	Etype_DragonSword,
	Ctype_HPpotion,
	Ctype_ATKpotion
};
void Bag::Root(int icode) { own[icode]++; } //������ ȹ��
int Bag::ShowBag(void) {//���� �����ֱ�
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	if (own[Item::Etype_WoodSword] != 0)
		cout << "0.������: " << own[Item::Etype_WoodSword] << "��" << endl;
	if (own[Item::Etype_IronSword] != 0)
		cout << "1.ö����: " << own[Item::Etype_IronSword] << "��" << endl;
	if (own[Item::Etype_PriestSword] != 0)
		cout << "2.�������ǰ�: " << own[Item::Etype_PriestSword] << "��" << endl;
	if (own[Item::Etype_DragonSword] != 0)
		cout << "3.���: " << own[Item::Etype_DragonSword] << "��" << endl;
	cout << "4.ü������: " << own[Item::Ctype_HPpotion] << "��" << endl;
	cout << "5.������: " << own[Item::Ctype_ATKpotion] << "��" << endl << endl << endl;
	cout << "��� ������ ���ڸ�, �ڷΰ����� ����Ű�� �����ÿ�";
	while (1) {//��ɾ� �Է±��� ���ѹݺ�
		key = _getch();
		if (key == 13) //���� �Է�
			return -1;
		if (48 <= key && key <= 53) {//0~5 �Է�
			key -= 48;
			if (own[key] > 0) {//��� �ִٸ�
				own[key]--; //���濡�� 1������
			}
			else {//��� ���ٸ�
				key = -2;//-2�� ��ȯ
			}
			return key;
		}
	}
}
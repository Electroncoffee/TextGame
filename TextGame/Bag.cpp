#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Bag.h"

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
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
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
	while (1) {//��ɾ� �Է±��� ���ѹݺ�
		key = _getch();
		if (key == 13) //���� �Է�
			return -1;
		if (48 <= key && key <= 53) {//0~5 �Է�
			key -= 48;//int���� ���
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
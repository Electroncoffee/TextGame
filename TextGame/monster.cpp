#include <iostream>
#include <Windows.h>
#include "monster.h"

enum Monster
{
	Mon_Bat, //0
	Mon_Wolf,
	Mon_devotee,
	Mon_DragonKnight,
	Mon_Priest,
	Mon_Dragon
};

char Monster_Name[6][20] = { "����","����","�ŵ�","����","������","��" };
char Monster_Status[6][3] = { {6,2,5},{12,3,10},{15,5,15},{25,15,25},{20,10,40},{40,20,60} }; //hp,pow,exp

void Battle_Monster::Init_Monster(int code)//�����ʱ�ȭ
{
	hp = Monster_Status[code][0];
	pow = Monster_Status[code][1];
	drop_exp = Monster_Status[code][2];
	Monster_code = code;
}
//���� üũ�Լ�
int Battle_Monster::Check_HP(void) { return hp; }
int Battle_Monster::Check_Exp(void) { return drop_exp; }
int Battle_Monster::Check_Mcode(void) const { return Monster_code; }
//����
int Battle_Monster::Attack(void) {
	std::cout << Monster_Name[Monster_code] << "�� ����!" << std::endl;
	return pow;
}
//�����Լ�
int Battle_Monster::Damage(int damage)
{
	std::cout << Monster_Name[Monster_code] << "��(��)" << damage << "�� ���ظ� �Ծ���!" << std::endl;
	hp -= damage;
	if (hp > 0)
		return 0;
	else
		return 1;
}
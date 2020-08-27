#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__

class Battle_Monster
{
private:
	int hp, pow, drop_exp;
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
	void Init_Monster(int code);
	int Check_HP(void);
	int Check_Exp(void);
	int Check_Mcode(void) const;
	int Attack(void);
	int Damage(int damage);
};

#endif // !__MONSTER_H__

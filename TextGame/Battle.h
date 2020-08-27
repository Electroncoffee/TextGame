#pragma once
#ifndef __BATTLE_H__
#define __BATTLE_H__
#include "monster.h"
#include "hero.h"

class AllAction
{
private:
	int flag;
	int level;
public:
	int Battle(Battle_Monster &Monster, character &Hero);
	void Action(character &Hero);
	int Item_Drop(int code, character &Hero);
};
#endif // !__BATTLE_H__

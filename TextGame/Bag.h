#pragma once
#ifndef __BAG_H__
#define __BAG_H__

class Bag //배낭
{
private:
	int own[6] = { 0,0,0,0,0,0 };
	int key = 0;
public:
	void Root(int icode);//아이템 루팅
	int ShowBag(void); //가방 보여주기
};

#endif // !__BAG_H__

#pragma once
#ifndef __BAG_H__
#define __BAG_H__

class Bag //�賶
{
private:
	int own[6] = { 0,0,0,0,0,0 };
	int key = 0;
public:
	void Root(int icode);//������ ����
	int ShowBag(void); //���� �����ֱ�
};

#endif // !__BAG_H__

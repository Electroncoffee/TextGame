#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int maxlife = 10;//ĳ������ �ִ� �����ġ ���������� ����
int life = 10;// ĳ������ �����ġ
int power = 5;// ĳ������ ���ݼ�ġ
char itemname[7][20] = { "����","������","ö����","�������ǰ�","���","ü������","�Ű��ڱؾ๰" };//����4�������� Ȯ���� ���Եд�
char monstername[7][20] = { "����","����","����","�ŵ�","����","������","��" };//������� ���� �ŵ��� ���簡 ���µ� ���ü��ְ� ����� ���ڴ�
int itemstate[7] = { 0,5,10,18,20,6,1 };//�������۵��� ���ݷ� ���� ü��ȸ�����ص��� ���Ϸ� ��Ÿ�´�. ���ǿ��°� �˸��� ��ġ�� ���Ҽ��ְ�����
int monsterstate[7][2] = { {0,0},{7,2},{4,1},{10,4},{12,5},{20,10},{30,15} };
int myequip = 0;
int mybag[7] = { 0,1,0,0,0,1,1, };
int itemcount[2] = { 0,0 };//ü������ �Ű��ڱؾ๰ ����
int nowmonster[2] = { 0,0 };

void war(int i)//���� 
{
	nowmonster[0] = monsterstate[i][0];
	nowmonster[1] = monsterstate[i][1];
	printf("\n\n%s��(��)��Ÿ����\n", monstername[i]);
	while (!((maxlife <= 0) | (nowmonster[0] <= 0)))
	{
		printf("\n\n\n ����ü��: %d \n %s��ü��: %d\n\n\n", life, monstername[i], nowmonster[0]);
		printf("���ǰ���!\n%d�ǵ�������������\n\n", power);
		Sleep(2);
		nowmonster[0] -= power;
		printf("%s�ǰ���!\n%d�ǵ�������������\n\n", monstername[i], nowmonster[1]);
		Sleep(1);
		life -= nowmonster[1];
	}
	if (life <= 0) {
		printf("�й�...\n\n");
	}
	else if (nowmonster[0] <= 0) {
		printf("�¸�!\n\n");
		Sleep(2);
	}
}

void event(void);//Ž�� 

void condition(void)//������ �����ش�
{
	printf("\n\n�ִ�ü��:%d\n����ü��:%d\n���ݷ�:%d\n\n��������:%s\n", maxlife, life, power, itemname[myequip]);
	Sleep(2);
}

void mounting(int i)//��� ������ ���ĺ�ȯ�Լ�
{
	if (!(myequip == 0))
	{
		power -= itemstate[myequip];
		myequip = i;
		power += itemstate[myequip];
	}
	else if (myequip == 0) {
		power += itemstate[i];
		myequip = i;
	}
	printf("\n�����Ϸ�");
	condition();
}

void equip(void)//������� ��ִ��� �˷��ִ� �Լ�
{
	int i = 1;
	char key = 0;
	while (i < 7)
	{
		if (mybag[i] == 1)
		{
			printf("(%d)%s", i, itemname[i]);
			if (i == 5)
			{
				printf("-------%d��", itemcount[0]);
			}
			else if (i == 6) {
				printf("---%d��", itemcount[1]);
			}
			printf("\n");
		}
		i++;
	}
error:
	printf("\n����� ����� �����Է�.");
	key = _getch();
	switch (key)
	{
	case 49://1�����
		if (mybag[1] == 1)
		{
			mounting(1);
		}
		else if (mybag[1] == 0) {
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
			goto error;
		}
		break;
	case 50://2�����
		if (mybag[2] == 1)
		{
			mounting(2);
			printf("���Ϸ�");
		}
		else if (mybag[2] == 0) {
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
			goto error;
		}
		break;
	case 51://3�����
		if (mybag[3] == 1)
		{
			mounting(3);
		}
		else if (mybag[3] == 0) {
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
			goto error;
		}
		break;
	case 52://4�����
		if (mybag[4] == 1)
		{
			mounting(4);
		}
		else if (mybag[4] == 0) {
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
			goto error;
		}
		break;
	case 53://5����� ü������ �Ҹ���
		if (itemcount[0] == 0)
		{
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
		}
		else if (!(itemcount[0] == 0)) {
			maxlife += 2;
			itemcount[0] -= 1;
		}
		condition();
		break;
	case 54://6����� ���ݷ����� �Ҹ���
		if (itemcount[1] == 0)
		{
			printf("���� ���� ����Դϴ�  �ٽ��Է��Ͻÿ�\n\n");
		}
		else if (!(itemcount[1] == 0)) {
			power += 3;
			itemcount[1] -= 1;
		}
		condition();
		break;
	default:
		printf("�߸����Է� �ٽ��Է��Ͻÿ�\n\n");
		goto error;
		break;

	}
}
int(void)//�������� �����ൿ�� �������� �Լ�
{
	char i = 0;// ���뵵�� ��Ȯ�ϱ⿡ char�� ���
	char key = 0;
	while (!(key == 13))//�ൿ ���ϱ�
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n���� �ൿ�� ���ұ�?\n\n\n(1)�����   (2)������   (3)�޽�   (4)Ž��\n");//���� ������ �ָ��ؼ� ���̳Ѿ�°� �޽İ� Ž��ܿ� ����
		switch (i)
		{
		case 0:
			printf("   --------\n\n\n\n\n\n\n");
			break;
		case 1:
			printf("                 --------\n\n\n\n\n\n\n");
			break;
		case 2:
			printf("                               ----\n\n\n\n\n\n\n");
			break;
		case 3:
			printf("                                         ----\n\n\n\n\n\n\n");
		}
		key = _getch();
		if (key == -32)
		{
			key = _getch();
			switch (key)
			{
			case 75://�¹�ư 
				if (!(i == 0))
					i -= 1;
				break;
			case 77://���ư 
				if (!(i == 3))
					i += 1;
				break;
			}
		}
	}
	switch (i)
	{
	case 0:
		equip();
		break;
	case 1:
		condition();
		break;
	case 2:
		if (life <= (maxlife - 2))//ü��ȸ���ý���
		{
			life += 2;
		}
		else
		{
			life = maxlife;
		}
		printf("\n\nü����2 ȸ���Ǿ���.\n\n");
		Sleep(2);
		break;
	case 3:
		event();
		break;
	}
	return i;
}

void how(void)//���ӹ�� 
{
	int i;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----<���ӹ��>----\n\n�ؽ�Ʈ��� �����̹� ��������\n�Ϸ縶�� �ൿ�� ���� �̺�Ʈ�� �Ͼ�ϴ�.\n�̺�Ʈ�� ��ó�ϸ鼭 ü���� ������ ��Ƴ����ô�.\n\n�ƹ�Ű�� ������ �����մϴ�.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	scanf_s("%d", &i);//�ƹ����̳��Է� 
}

int main(void)
{
	int day = 1;// ������� �����ϼ� ǥ�� ����� ���� 
	int i = 0; // �÷��׸� ���ﶧ ���� �ٿ뵵 ���� 
	char key = 0;// Ű������ �Է°��� ���ڷ� �ޱ����� ���� 
	while (!(key == 13))// ����ȭ�� ���� 
	{
		printf("\n\n\n\n\n\n\n\n\n\n                                                    textgame\n\n\n\n\n\n\n\n                         ���ӽ���                                         ���ӹ��\n");
		switch (i)
		{
		case 0:
			printf("                         --------\n\n\n\n\n\n\n\n\n\n");
			break;
		case 1:
			printf("                                                                          --------\n\n\n\n\n\n\n\n\n\n");
			break;
		}
		key = _getch();// Ű���� �Է½� ��� ���� �޸��� 
		if (key == -32)
		{
			key = _getch();
			switch (key)
			{
			case 75://�¹�ư 
				if (i == 1) {
					i -= 1;
				}
				break;

			case 77://���ư 
				if (i == 0) {
					i += 1;
				}
			}
		}
	}//����ȭ�鳡 �÷��׿����� ���� 
	if (i == 1)//���ӹ������ 
	{
		how();
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n���� ����.\n������ �ؾ��ұ�\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//���۸�Ʈ 
	Sleep(3);
	while (!(life <= 0))//�����ӽ��� ü����0�϶� �������� ��� Ʋ¥��Ϸ���  !(life==0)�ֱ� 
	{
		action();
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n���̾���.\n�������´�.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//���ӿ�����Ʈ 
	return 0;
}

void event(void)
{
	srand(time(NULL));//�õ����
	int key = 0;
	int random = (rand() % 3) + 1;//�������ڻ���
	printf("\n����%d\n", random);
no:
	if (random == 1)
	{
		printf("\n\n���ڸ� �߰��ߴ�.\n\n���ڽ��ϱ�? (1)��  (2)�ƴϿ�");//�ð������� ��ĵ������ �ٸ��ŷ� ����
		scanf_s("%d", &key);
		if (!((key == 1) | (key == 2)))
		{
			printf("�߸����Է� �ٽ��Է��Ͻÿ�\n\n");
			goto no;
		}
		else if (key == 1) {
			random = (rand() % 20) + 1;
			printf("%d", random);
			switch (random)
			{
			case 20:
				random = 4;
				break;

			case 19:
				random = 3;
				break;

			case 18:
				random = 3;
				break;

			case 17:
				random = 3;
				break;

			case 16:
				random = 5;
				break;

			case 15:
				random = 5;
				break;

			case 14:
				random = 5;
				break;

			case 13:
				random = 6;
				break;

			case 12:
				random = 6;
				break;

			case 11:
				random = 6;
				break;

			case 10:
				random = 6;
				break;

			case 9:
				random = 2;
				break;

			case 8:
				random = 2;
				break;

			case 7:
				random = 2;
				break;

			case 6:
				random = 2;
				break;

			case 5:
				random = 1;
				break;

			case 4:
				random = 1;
				break;

			case 3:
				random = 1;
				break;

			case 2:
				random = 1;
				break;

			case 1:
				random = 1;
				break;
			}
			printf("\n\n���ڿ���\"%s\"��(��)����־���\n\n", itemname[random]);
			mybag[random] = 1;
			if (random == 5) {
				itemcount[0] += 1;
			}
			else if (random == 6) {
				itemcount[1] += 1;
			}
		}
		else if (key == 2) {
			printf("\n\n���ڸ� �����ƴ�\n\n");
		}
	}
	else if (!(random == 1)) {
		random = (rand() % 50) + 1;
		if (random == 50) {
			random = 6;
		}
		else if ((random <= 49) & (random >= 48)) {
			random = 5;
		}
		else if ((random <= 47) & (random >= 45)) {
			random = 4;
		}
		else if ((random <= 45) & (random >= 40)) {
			random = 3;
		}
		else if ((random <= 39) & (random >= 20)) {
			random = 2;
		}
		else if (random <= 19) {
			random = 1;
		}
		war(random);
	}
}
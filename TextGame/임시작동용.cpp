#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int maxlife = 10;//캐릭터의 최대 생명수치 방패장착시 증가
int life = 10;// 캐릭터의 생명수치
int power = 5;// 캐릭터의 공격수치
char itemname[7][20] = { "없음","목제검","철제검","제사장의검","용검","체력포션","신경자극약물" };//뒤의4아이템은 확률을 적게둔다
char monstername[7][20] = { "없음","늑대","박쥐","신도","용기사","제사장","용" };//제사장과 용은 신도와 용기사가 나온뒤 나올수있게 만들면 좋겠다
int itemstate[7] = { 0,5,10,18,20,6,1 };//각아이템들의 공격력 방어력 체력회복수준등을 단일로 나타냈다. 조건에맞게 알맞은 수치에 더할수있게하자
int monsterstate[7][2] = { {0,0},{7,2},{4,1},{10,4},{12,5},{20,10},{30,15} };
int myequip = 0;
int mybag[7] = { 0,1,0,0,0,1,1, };
int itemcount[2] = { 0,0 };//체력포션 신경자극약물 개수
int nowmonster[2] = { 0,0 };

void war(int i)//전투 
{
	nowmonster[0] = monsterstate[i][0];
	nowmonster[1] = monsterstate[i][1];
	printf("\n\n%s이(가)나타났다\n", monstername[i]);
	while (!((maxlife <= 0) | (nowmonster[0] <= 0)))
	{
		printf("\n\n\n 나의체력: %d \n %s의체력: %d\n\n\n", life, monstername[i], nowmonster[0]);
		printf("나의공격!\n%d의데미지를입혔다\n\n", power);
		Sleep(2);
		nowmonster[0] -= power;
		printf("%s의공격!\n%d의데미지를입혔다\n\n", monstername[i], nowmonster[1]);
		Sleep(1);
		life -= nowmonster[1];
	}
	if (life <= 0) {
		printf("패배...\n\n");
	}
	else if (nowmonster[0] <= 0) {
		printf("승리!\n\n");
		Sleep(2);
	}
}

void event(void);//탐색 

void condition(void)//스탯을 보여준다
{
	printf("\n\n최대체력:%d\n현재체력:%d\n공격력:%d\n\n현재장착:%s\n", maxlife, life, power, itemname[myequip]);
	Sleep(2);
}

void mounting(int i)//장비 장착시 스탠변환함수
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
	printf("\n장착완료");
	condition();
}

void equip(void)//현재장비가 몇개있는지 알려주는 함수
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
				printf("-------%d개", itemcount[0]);
			}
			else if (i == 6) {
				printf("---%d개", itemcount[1]);
			}
			printf("\n");
		}
		i++;
	}
error:
	printf("\n사용할 장비의 숫자입력.");
	key = _getch();
	switch (key)
	{
	case 49://1번장비
		if (mybag[1] == 1)
		{
			mounting(1);
		}
		else if (mybag[1] == 0) {
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
			goto error;
		}
		break;
	case 50://2번장비
		if (mybag[2] == 1)
		{
			mounting(2);
			printf("사용완료");
		}
		else if (mybag[2] == 0) {
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
			goto error;
		}
		break;
	case 51://3번장비
		if (mybag[3] == 1)
		{
			mounting(3);
		}
		else if (mybag[3] == 0) {
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
			goto error;
		}
		break;
	case 52://4번장비
		if (mybag[4] == 1)
		{
			mounting(4);
		}
		else if (mybag[4] == 0) {
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
			goto error;
		}
		break;
	case 53://5번장비 체력포션 소모형
		if (itemcount[0] == 0)
		{
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
		}
		else if (!(itemcount[0] == 0)) {
			maxlife += 2;
			itemcount[0] -= 1;
		}
		condition();
		break;
	case 54://6번장비 공격력포션 소모형
		if (itemcount[1] == 0)
		{
			printf("현재 없는 장비입니다  다시입력하시오\n\n");
		}
		else if (!(itemcount[1] == 0)) {
			power += 3;
			itemcount[1] -= 1;
		}
		condition();
		break;
	default:
		printf("잘못된입력 다시입력하시오\n\n");
		goto error;
		break;

	}
}
int(void)//비전투시 무슨행동을 취할지의 함수
{
	char i = 0;// 사용용도가 명확하기에 char을 사용
	char key = 0;
	while (!(key == 13))//행동 정하기
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n무슨 행동을 취할까?\n\n\n(1)장비사용   (2)장비상태   (3)휴식   (4)탐색\n");//턴의 개념이 애매해서 턴이넘어가는건 휴식과 탐사외에 없다
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
			case 75://좌버튼 
				if (!(i == 0))
					i -= 1;
				break;
			case 77://우버튼 
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
		if (life <= (maxlife - 2))//체력회복시스템
		{
			life += 2;
		}
		else
		{
			life = maxlife;
		}
		printf("\n\n체력이2 회복되었다.\n\n");
		Sleep(2);
		break;
	case 3:
		event();
		break;
	}
	return i;
}

void how(void)//게임방법 
{
	int i;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n----<게임방법>----\n\n텍스트기반 서바이벌 게임으로\n하루마다 행동을 한후 이벤트가 일어납니다.\n이벤트에 대처하면서 체력을 유지해 살아남읍시다.\n\n아무키나 누르면 시작합니다.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	scanf_s("%d", &i);//아무값이나입력 
}

int main(void)
{
	int day = 1;// 현재맵의 생존일수 표시 생명과 같음 
	int i = 0; // 플래그를 세울때 쓰일 다용도 변수 
	char key = 0;// 키보드의 입력값을 숫자로 받기위한 변수 
	while (!(key == 13))// 시작화면 시작 
	{
		printf("\n\n\n\n\n\n\n\n\n\n                                                    textgame\n\n\n\n\n\n\n\n                         게임시작                                         게임방법\n");
		switch (i)
		{
		case 0:
			printf("                         --------\n\n\n\n\n\n\n\n\n\n");
			break;
		case 1:
			printf("                                                                          --------\n\n\n\n\n\n\n\n\n\n");
			break;
		}
		key = _getch();// 키보드 입력시 사용 이하 메모장 
		if (key == -32)
		{
			key = _getch();
			switch (key)
			{
			case 75://좌버튼 
				if (i == 1) {
					i -= 1;
				}
				break;

			case 77://우버튼 
				if (i == 0) {
					i += 1;
				}
			}
		}
	}//시작화면끝 플래그에따라 실행 
	if (i == 1)//게임방법실행 
	{
		how();
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n눈을 떴다.\n무엇을 해야할까\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//시작멘트 
	Sleep(3);
	while (!(life <= 0))//본게임시작 체력이0일때 게임종료 모든 틀짜기완료후  !(life==0)넣기 
	{
		action();
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n힘이없다.\n눈을감는다.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//게임오버멘트 
	return 0;
}

void event(void)
{
	srand(time(NULL));//시드생성
	int key = 0;
	int random = (rand() % 3) + 1;//랜덤숫자생성
	printf("\n난수%d\n", random);
no:
	if (random == 1)
	{
		printf("\n\n상자를 발견했다.\n\n열겠습니까? (1)예  (2)아니오");//시간남으면 스캔프말고 다른거로 가자
		scanf_s("%d", &key);
		if (!((key == 1) | (key == 2)))
		{
			printf("잘못된입력 다시입력하시오\n\n");
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
			printf("\n\n상자에는\"%s\"이(가)들어있었다\n\n", itemname[random]);
			mybag[random] = 1;
			if (random == 5) {
				itemcount[0] += 1;
			}
			else if (random == 6) {
				itemcount[1] += 1;
			}
		}
		else if (key == 2) {
			printf("\n\n상자를 지나쳤다\n\n");
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
#include <iostream>
#include <random>

int main(void)
{
	std::random_device rd;

	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());

	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(1, 5);
	int one = 0, two = 0, three = 0, four = 0, five = 0;
	for (int i = 0; i < 10000; i++) {
		switch (dis(gen))
		{
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		case 4:
			four++;
			break;
		case 5:
			five++;
			break;
		}
	}
	std::cout << one << std::endl << two << std::endl << three << std::endl << four << std::endl << five << std::endl;
}
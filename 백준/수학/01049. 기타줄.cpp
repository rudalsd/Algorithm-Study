#include <iostream>

using namespace std;

int N, M;

int main()
{
	cin >> N >> M;

	int minSet = 99999;
	int min = 99999;

	for (int i = 0; i < M; i++) {
		int set = 0, str = 0;
		cin >> set >> str;
		if (minSet > set) {
			minSet = set;			//패키지의 최솟값
		}
		if (min > str) {
			min = str;				//낱개의 최솟값
		}
	}

	int cost = 0;

	if (minSet > 6 * min) {
		cost = N * min;				//낱개로 사는 것이 패키지로 사는 것 보다 무조건 나을 때
	}
	else {
		cost = N / 6 * minSet;
		int other = N % 6;
		if (minSet < other * min) {	//패키지의 가격이 나머지를 낱개로 사는 것보다 쌀 때
			cost += minSet;
		}
		else {						//패키지의 가격이 나머지를 낱개로 사는 것보다 비쌀 때
			cost += other * min;
		}
	}

	cout << cost;
}
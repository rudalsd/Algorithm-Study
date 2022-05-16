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
			minSet = set;			//��Ű���� �ּڰ�
		}
		if (min > str) {
			min = str;				//������ �ּڰ�
		}
	}

	int cost = 0;

	if (minSet > 6 * min) {
		cost = N * min;				//������ ��� ���� ��Ű���� ��� �� ���� ������ ���� ��
	}
	else {
		cost = N / 6 * minSet;
		int other = N % 6;
		if (minSet < other * min) {	//��Ű���� ������ �������� ������ ��� �ͺ��� �� ��
			cost += minSet;
		}
		else {						//��Ű���� ������ �������� ������ ��� �ͺ��� ��� ��
			cost += other * min;
		}
	}

	cout << cost;
}
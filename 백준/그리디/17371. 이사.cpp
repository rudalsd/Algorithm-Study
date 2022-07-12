#include<iostream>
#include<cmath>

using namespace std;

int N;

struct pos {
	int x;
	int y;
};

pos arr[1000];
int ans;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	double minDist = 9999999;

	for (int i = 0; i < N; i++) {
		int x = 0; int y = 0;
		double maxDist = 0;
		for (int j = 0; j < N; j++) {	//i��° ������ j��° ������ �Ÿ� �� ���� �� �Ÿ��� maxDist�� ����
			double dist = sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2));
			maxDist = max(maxDist, dist);
		}

		if (minDist > maxDist) {		//maxDist �� ���� ª�� �Ÿ��� minDist�� �����ϰ� idx�� ans�� ����
			ans = i;
			minDist = maxDist;
		}
	}

	cout << arr[ans].x << " " << arr[ans].y;
}
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
		for (int j = 0; j < N; j++) {	//i번째 점부터 j번째 점까지 거리 중 가장 먼 거리를 maxDist에 저장
			double dist = sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2));
			maxDist = max(maxDist, dist);
		}

		if (minDist > maxDist) {		//maxDist 중 가장 짧은 거리를 minDist에 저장하고 idx를 ans에 저장
			ans = i;
			minDist = maxDist;
		}
	}

	cout << arr[ans].x << " " << arr[ans].y;
}
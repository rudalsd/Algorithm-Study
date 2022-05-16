#include <iostream>

using namespace std;

int pos[19][4][2] = {				//모든 경우의 수 방향 배열
	0,0,0,1,0,2,0,3,
	0,0,1,0,2,0,3,0,
	0,0,0,1,1,0,1,1,
	0,1,1,0,1,1,1,2,
	0,0,0,1,0,2,1,1,
	0,0,1,0,1,1,2,0,
	0,1,1,0,1,1,2,1,
	0,0,0,1,1,0,2,0,
	0,0,0,1,1,1,2,1,
	0,0,1,0,1,1,1,2,
	0,2,1,0,1,1,1,2,
	0,1,1,1,2,0,2,1,
	0,0,1,0,2,0,2,1,
	0,0,0,1,0,2,1,2,
	0,0,0,1,0,2,1,0,
	0,1,0,2,1,0,1,1,
	0,0,0,1,1,1,1,2,
	0,1,1,0,1,1,2,0,
	0,0,1,0,1,1,2,1,
};

int N, M;
int arr[550][550];

int Cnt(int y, int x)										//각각의 좌표에서 최댓값 구하기
{
	int max = 0;
	for (int i = 0; i < 19; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int yy = y + pos[i][j][0];
			int xx = x + pos[i][j][1];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				sum += arr[yy][xx];
			}
			else {
				sum = 0;
				break;
			}
		}
		if (max < sum) {
			max = sum;
		}
	}

	return max;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum = Cnt(i, j);				//각각의 좌표 Cnt함수로 전달
			if (max < sum) {
				max = sum;
			}
		}
	}

	cout << max;
}
#include<iostream>
#include<cstring>

using namespace std;

int N, K;
int arr[10][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void put()	//어항을 일렬로 만드는 함수
{
	int temp[101] = { 0 };
	int cur = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 9; j >= 0; j--) {
			if (arr[j][i] == 0) break;
			temp[cur] = arr[j][i];
			cur++;
		}
	}

	memset(arr, 0, sizeof(arr));

	for (int i = 1; i < cur; i++) {
		arr[9][i] = temp[i];
	}
}

void turn(int arr[][10], int num)	//배열을 시계방향으로 90도 회전
{
	int temp[10][10] = { 0 };

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			temp[j][num - i - 1] = arr[i][j];
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void airRoll()	//첫 공중부양
{
	int cur = 1;
	for (int i = 1; i <= 10; i++) {
		int temp[10][10] = { 0 };

		if (cur + 2 * i - 1 > N) return;

		for (int j = cur; j < cur + i; j++) {
			for (int k = 10 - i; k < 10; k++) {
				temp[k + i - 10][j - cur] = arr[k][j];
				arr[k][j] = 0;
			}
		}

		turn(temp, i);

		cur += i;

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				arr[9 - i + j][cur + k] = temp[j][k];
			}
		}

		if (cur + 2 * i > N) return;

		for (int j = cur; j < cur + i; j++) {
			for (int k = 9 - i; k < 10; k++) {
				temp[k + i - 9][j - cur] = arr[k][j];
				arr[k][j] = 0;
			}
		}

		turn(temp, i + 1);

		cur += i;

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i + 1; k++) {
				arr[9 - i + j][cur + k] = temp[j][k];
			}
		}
	}
}

void air()	//두번째 공중부양
{
	int cur = 1;

	for (int i = N / 2; i > 0; i--) {
		arr[8][N / 2 + cur] = arr[9][i];
		cur++;
		arr[9][i] = 0;
	}

	cur = 1;

	for (int i = N / 4 * 3; i > N / 2; i--) {
		arr[6][N / 4 * 3 + cur] = arr[9][i];
		arr[7][N / 4 * 3 + cur] = arr[8][i];
		arr[9][i] = 0;
		arr[8][i] = 0;
		cur++;
	}

}

void adjust()	//물고기 수 조절
{
	int temp[10][101] = { 0 };

	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= N; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int yy = i + dy[k];
					int xx = j + dx[k];
					if (yy >= 0 && yy < 10 && xx > 0 && xx <= N) {
						if (arr[yy][xx] > 0) {
							if (arr[i][j] > arr[yy][xx]) {
								int dif = arr[i][j] - arr[yy][xx];
								dif /= 5;
								if (dif > 0) {
									temp[i][j] -= dif;
									temp[yy][xx] += dif;
								}
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[9][i]);
	}

	int cnt = 0;

	while (1) {
		int Min = 987654321;
		int Max = 0;
		for (int i = 1; i <= N; i++) {
			Min = min(Min, arr[9][i]);
			Max = max(Max, arr[9][i]);
		}

		if (Max - Min <= K) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 1; i <= N; i++) {
			if (arr[9][i] == Min) arr[9][i]++;
		}

		airRoll();

		adjust();

		put();

		air();

		adjust();

		put();

		cnt++;
	}
}
#include<iostream>
#include<queue>

using namespace std;

int R, C, T;

int arr[50][50];
int temp[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int airY[2];

void diff()		//먼지 확산
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int cnt = 0;
			if (arr[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int yy = i + dy[k];
					int xx = j + dx[k];
					if (yy >= 0 && yy < R && xx >= 0 && xx < C) {
						if (arr[yy][xx] > -1) {
							temp[yy][xx] += arr[i][j] / 5;
							cnt++;
						}
					}
				}
				temp[i][j] -= (int)(arr[i][j] / 5) * cnt;
			}
		}
	}
}

void clean()		//공기 순환
{
	for (int i = airY[0] - 1; i > 0; i--) {
		temp[i][0] = temp[i - 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		temp[0][i] = temp[0][i + 1];
	}
	for (int i = 0; i < airY[0]; i++) {
		temp[i][C - 1] = temp[i + 1][C - 1];
	}
	for (int i = C - 1; i >= 1; i--) {
		if (i == 1) {
			temp[airY[0]][i] = 0;
		}
		else {
			temp[airY[0]][i] = temp[airY[0]][i - 1];
		}
	}

	for (int i = airY[1] + 1; i < R - 1; i++) {
		temp[i][0] = temp[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		temp[R - 1][i] = temp[R - 1][i + 1];
	}
	for (int i = R - 1; i > airY[1]; i--) {
		temp[i][C - 1] = temp[i - 1][C - 1];
	}
	for (int i = C - 1; i >= 1; i--) {
		if (i == 1) {
			temp[airY[1]][i] = 0;
		}
		else {
			temp[airY[1]][i] = temp[airY[1]][i - 1];
		}
	}
}

int main()
{
	cin >> R >> C >> T;
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1) {
				airY[cnt++] = i;
			}
		}
	}

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		diff();
		clean();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0) {
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}
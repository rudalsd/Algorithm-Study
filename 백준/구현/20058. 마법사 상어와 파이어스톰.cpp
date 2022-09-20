#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int N, Q;
int arr[64][64];
int temp[64][64];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(int y, int x)	//덩어리 크기
{
	queue<pair<int, int>> q;
	q.push({ y,x });

	temp[y][x] = 0;
	int cnt = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (temp[yy][xx] > 0) {
					temp[yy][xx] = 0;
					q.push({ yy,xx });
					cnt++;
				}
			}
		}
	}

	return cnt;
}

bool check(int y, int x)	//얼음이 주변에 3개 이상 있는지
{
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
			if (arr[yy][xx] > 0) {
				cnt++;
			}
		}
	}

	if (cnt >= 3) {
		return true;
	}
	else {
		return false;
	}
}

void firestorm()	//파이어스톰 적용
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > 0) {
				if (!check(i, j)) {
					temp[i][j] = arr[i][j] - 1;
				}
				else {
					temp[i][j] = arr[i][j];
				}
			}
			else {
				temp[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void turn(int y, int x, int L)	//90도 회전
{
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			temp[i][j] = arr[y + i][x + j];
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			arr[y + i][x + L - j - 1] = temp[j][i];
		}
	}
}

void devide(int L)	//구역 나누기
{
	for (int i = 0; i < N; i += L) {
		for (int j = 0; j < N; j += L) {
			turn(i, j, L);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &Q);

	N = pow(2, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < Q; i++) {
		int L;
		scanf("%d", &L);
		L = pow(2, L);
		devide(L);

		firestorm();
	}

	int ans = 0;
	int Max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += arr[i][j];
			if (temp[i][j] > 0) {
				int cnt = bfs(i, j);
				Max = max(cnt, Max);
			}
		}
	}

	printf("%d\n%d", ans, Max);
}

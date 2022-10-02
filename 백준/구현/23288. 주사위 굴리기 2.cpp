#include<iostream>
#include<queue>

using namespace std;

int N, M, K;
int arr[20][20];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int dir;
int top = 1;
int dice[3][3] = {	//초기 주사위
	0,2,0,
	4,6,3,
	0,5,0
};
int y, x;
int ans;

int bfs(int y, int x)	//같은 숫자가 이어져 있는 개수 return
{
	queue<pair<int, int>> q;
	int visited[20][20] = { 0 };
	q.push({ y,x });
	visited[y][x] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1 && arr[y][x] == arr[yy][xx]) {
					visited[yy][xx] = 1;
					cnt++;
					q.push({ yy,xx });
				}
			}
		}
	}

	return cnt;
}

void move(int dir)	//주사위 이동
{
	if (dir == 0) {
		int temp = top;
		top = dice[1][0];
		for (int i = 0; i < 2; i++) {
			dice[1][i] = dice[1][i + 1];
		}
		dice[1][2] = temp;
	}
	else if (dir == 1) {
		int temp = top;
		top = dice[0][1];
		for (int i = 0; i < 2; i++) {
			dice[i][1] = dice[i + 1][1];
		}
		dice[2][1] = temp;
	}
	else if (dir == 2) {
		int temp = top;
		top = dice[1][2];
		for (int i = 2; i > 0; i--) {
			dice[1][i] = dice[1][i - 1];
		}
		dice[1][0] = temp;
	}
	else {
		int temp = top;
		top = dice[2][1];
		for (int i = 2; i > 0; i--) {
			dice[i][1] = dice[i - 1][1];
		}
		dice[0][1] = temp;
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int yy = y + dy[dir];
		int xx = x + dx[dir];

		if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
			move(dir);
			ans += arr[yy][xx] * bfs(yy, xx);
		}
		else {
			dir += 2;
			if (dir > 3) dir %= 4;
			if (dir < 0) dir += 4;
			move(dir);
			yy = y + dy[dir];
			xx = x + dx[dir];
			ans += arr[yy][xx] * bfs(yy, xx);
		}

		y = yy;
		x = xx;

		if (arr[y][x] > dice[1][1]) {
			dir--;
		}
		else if (arr[y][x] < dice[1][1]) {
			dir++;
		}

		if (dir > 3) dir = 0;
		if (dir < 0) dir = 3;
	}

	printf("%d", ans);
}
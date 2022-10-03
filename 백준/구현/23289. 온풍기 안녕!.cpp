#include<iostream>
#include<queue>

using namespace std;

int R, C, K, W;
int arr[21][21];
int wall[21][21][4];	//벽의 위치 배열
int temp[21][21];
int tempT[21][21];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int dr[5][3] = {	//온풍기 방향 배열
	0,0,0,
	-1,0,1,
	-1,0,1,
	-1,-1,-1,
	1,1,1
};
int dc[5][3] = {
	0,0,0,
	1,1,1,
	-1,-1,-1,
	-1,0,1,
	-1,0,1
};

struct pos {
	int y;
	int x;
	int temp;
};

bool check()	//온도를 조사해야 하는 모든 칸의 온도가 K이상인지 체크
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == 5) {
				if (temp[i][j] < K) {
					return false;
				}
			}
		}
	}

	return true;
}

void adjust()		//온도 조절
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			tempT[i][j] = temp[i][j];
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < 4; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];
				if (yy > 0 && yy <= R && xx > 0 && xx <= C && wall[i][j][k] != 1) {
					if (temp[i][j] < temp[yy][xx]) {
						int dif = temp[yy][xx] - temp[i][j];
						tempT[i][j] += dif / 4;
					}
					else if (temp[i][j] > temp[yy][xx]) {
						int dif = temp[i][j] - temp[yy][xx];
						tempT[i][j] -= dif / 4;
					}
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			temp[i][j] = tempT[i][j];
		}
	}

	for (int i = 1; i <= R; i++) {
		if (temp[i][1] > 0) {
			temp[i][1]--;
		}
		if (temp[i][C] > 0) {
			temp[i][C]--;
		}
	}

	for (int i = 2; i < C; i++) {
		if (temp[1][i] > 0) {
			temp[1][i]--;
		}
		if (temp[R][i] > 0) {
			temp[R][i]--;
		}
	}
}

void bfs(int y, int x, int dir)	//온풍기 확산
{
	int visited[21][21] = { 0 };
	queue<pos> q;
	q.push({ y,x,5 });
	visited[y][x] = 1;
	temp[y][x] += 5;

	while (!q.empty()) {
		int cury = q.front().y;
		int curx = q.front().x;
		int curt = q.front().temp;
		q.pop();

		if (curt == 0) continue;

		for (int i = 0; i < 3; i++) {
			int yy = cury + dr[dir][i];
			int xx = curx + dc[dir][i];
			if (yy > 0 && yy <= R && xx > 0 && xx <= C) {
				bool flag = false;
				if (visited[yy][xx] != 1) {
					if (dir == 1) {
						if (wall[yy][xx][3] != 1) {
							if (i == 0) {
								if (wall[yy][xx - 1][2] != 1) {
									flag = true;
								}
							}
							else if (i == 1) {
								flag = true;
							}
							else {
								if (wall[yy][xx - 1][0] != 1) {
									flag = true;
								}
							}
						}
					}
					else if (dir == 2) {
						if (wall[yy][xx][1] != 1) {
							if (i == 0) {
								if (wall[yy][xx + 1][2] != 1) {
									flag = true;
								}
							}
							else if (i == 1) {
								flag = true;
							}
							else {
								if (wall[yy][xx + 1][0] != 1) {
									flag = true;
								}
							}
						}
					}
					else if (dir == 3) {
						if (wall[yy][xx][2] != 1) {
							if (i == 0) {
								if (wall[yy + 1][xx][1] != 1) {
									flag = true;
								}
							}
							else if (i == 1) {
								flag = true;
							}
							else {
								if (wall[yy + 1][xx][3] != 1) {
									flag = true;
								}
							}
						}
					}
					else {
						if (wall[yy][xx][0] != 1) {
							if (i == 0) {
								if (wall[yy - 1][xx][1] != 1) {
									flag = true;
								}
							}
							else if (i == 1) {
								flag = true;
							}
							else {
								if (wall[yy - 1][xx][3] != 1) {
									flag = true;
								}
							}
						}
					}

					if (flag == true) {
						visited[yy][xx] = 1;
						temp[yy][xx] += curt - 1;
						q.push({ yy,xx,curt - 1 });
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &R, &C, &K);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d", &W);

	for (int i = 0; i < W; i++) {
		int x, y, t;
		scanf("%d %d %d", &y, &x, &t);
		if (t == 0) {
			wall[y][x][0] = 1;
			wall[y - 1][x][2] = 1;
		}
		else {
			wall[y][x][1] = 1;
			wall[y][x + 1][3] = 1;
		}
	}

	int ans = 0;

	while (1) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (arr[i][j] > 0 && arr[i][j] < 5) {
					int yy = i + dr[arr[i][j]][1];
					int xx = j + dc[arr[i][j]][1];
					bfs(yy, xx, arr[i][j]);
				}
			}
		}

		adjust();

		ans++;

		if (ans > 100) {
			printf("%d", 101);
			return 0;
		}

		if (check()) {
			printf("%d", ans);
			return 0;
		}
	}
}
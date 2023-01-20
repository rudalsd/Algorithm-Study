#include<iostream>
#include<queue>

using namespace std;

int N, M;
int Hx, Hy;
int Ex, Ey;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int arr[1001][1001];
int visited[1001][1001][2];

struct pos {
	int x;
	int y;
	int wall;
	int cnt;
};

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d", &Hx, &Hy);
	scanf("%d %d", &Ex, &Ey);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	queue<pos> q;

	q.push({ Hx,Hy,0,0 });
	visited[Hx][Hy][0] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int wall = q.front().wall;
		const int cnt = q.front().cnt;
		q.pop();

		if (y == Ey && x == Ex) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (xx > 0 && xx <= N && yy > 0 && yy <= M) {
				if (wall == 0 && arr[xx][yy] == 1) {
					if (visited[xx][yy][1] != 1) {
						visited[xx][yy][1] = 1;
						q.push({ xx,yy,1,cnt + 1 });
					}
				}
				if (arr[xx][yy] == 0) {
					if (visited[xx][yy][wall] != 1) {
						visited[xx][yy][wall] = 1;
						q.push({ xx,yy,wall,cnt + 1 });
					}
				}
			}
		}
	}

	printf("-1");
}
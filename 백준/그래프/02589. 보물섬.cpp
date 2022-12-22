#include<iostream>
#include<queue>

using namespace std;

int N, M;
char arr[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};

int bfs(int y, int x)
{
	int ret = 0;
	int visited[50][50] = { 0 };
	queue<node> q;

	q.push({ y,x,0 });

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		q.pop();

		if (visited[y][x] == 1) continue;
		visited[y][x] = 1;

		ret = max(ret, cnt);

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == 'L') {
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				ans = max(ans, bfs(i, j));
			}
		}
	}

	printf("%d", ans);
}
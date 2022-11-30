#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

char arr[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[1000][1000];
int w, h;

struct node {
	int y;
	int x;
	int cur;
	int cnt;
};

void bfs(queue<node> q)
{
	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cur = q.front().cur;
		const int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < h && xx >= 0 && xx < w) {
				if (cur == 1) {
					if (arr[yy][xx] == '.' || arr[yy][xx] == '@') {
						arr[yy][xx] = '*';
						q.push({ yy,xx,cur,cnt });
					}
				}
				else {
					if (visited[yy][xx] != 1 && arr[yy][xx] == '.') {
						visited[yy][xx] = 1;
						q.push({ yy,xx,cur,cnt + 1 });
					}
				}
			}
			else {
				if (cur == 0) {
					printf("%d\n", cnt + 1);
					return;
				}
			}
		}
	}

	printf("IMPOSSIBLE\n");
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		memset(visited, 0, sizeof(visited));
		int y, x;
		scanf("%d %d", &w, &h);
		queue<node> q;

		for (int i = 0; i < h; i++) {
			scanf("%s", arr[i]);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '*') {
					q.push({ i,j,1,0 });
				}
				if (arr[i][j] == '@') {
					y = i;
					x = j;
				}
			}
		}

		q.push({ y,x,0,0 });
		visited[y][x] = 1;

		bfs(q);
	}
}
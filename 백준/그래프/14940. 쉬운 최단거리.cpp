#include<iostream>
#include<queue>

using namespace std;

int n, m;
int arr[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[1000][1000];
int y, x;

struct node {
	int y;
	int x;
	int cnt;
};

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 987654321;
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				y = i;
				x = j;
			}
		}
	}

	queue<node> q;

	q.push({ y,x,0 });

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		q.pop();

		if (visited[y][x] < cnt) continue;
		visited[y][x] = cnt;

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy < n && xx >= 0 && xx < m && arr[yy][xx] != 0) {
				if (visited[yy][xx] > cnt + 1) {
					visited[yy][xx] = cnt + 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				printf("0 ");
			}
			else {
				if (visited[i][j] != 987654321) {
					printf("%d ", visited[i][j]);
				}
				else {
					printf("-1 ");
				}
			}
		}
		printf("\n");
	}
}
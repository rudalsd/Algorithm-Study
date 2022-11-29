#include<iostream>
#include<queue>

using namespace std;

int R, C;
char arr[1001][1001];
int visited[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cur;
	int cnt;
};

int main()
{
	scanf("%d %d", &R, &C);
	queue<node>q;
	int r, c;

	for (int i = 0; i < R; i++) {
		scanf("%s", &arr[i]);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'F') {
				q.push({ i,j,1 });
			}
			if (arr[i][j] == 'J') {
				r = i;
				c = j;
			}
		}
	}

	q.push({ r,c,0,0 });
	visited[r][c] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cur = q.front().cur;
		const int cnt = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < R && xx >= 0 && xx < C) {
				if (cur == 1) {
					if (arr[yy][xx] == '.') {
						arr[yy][xx] = 'F';
						q.push({ yy,xx,1 });
					}
				}
				else {
					if (arr[yy][xx] == '.') {
						if (visited[yy][xx] != 1) {
							visited[yy][xx] = 1;
							q.push({ yy,xx,0,cnt + 1 });
						}
					}
				}
			}
			else {
				if (cur == 0) {
					printf("%d", cnt + 1);
					return 0;
				}
			}
		}
	}

	printf("IMPOSSIBLE");
}
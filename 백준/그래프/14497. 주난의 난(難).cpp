#include<iostream>
#include<queue>

using namespace std;

int N, M;
int x, y, x2, y2;
int visited[301][301];
char arr[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	scanf("%d %d", &N, &M);

	scanf("%d %d %d %d", &x, &y, &x2, &y2);

	for (int i = 0; i < N; i++ ) {
		scanf("%s", arr[i]);
	}

	queue<pair<int, int>>q;

	int cnt = 0;

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
		cnt++;
		q.push({ x - 1, y - 1 });
		visited[x - 1][y - 1] = 1;

		while (!q.empty()) {
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
					if (visited[xx][yy] != 1) {
						visited[xx][yy] = 1;
						if (arr[xx][yy] == '1') {
							arr[xx][yy] = '0';
						}
						else if (arr[xx][yy] == '0') {
							q.push({ xx,yy });
						}
						else {
							printf("%d", cnt);
							return 0;
						}
					}
				}
			}
		}
	}
}
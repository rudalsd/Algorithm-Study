#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, K;

int arr[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	arr[y][x] = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == 1) {
					arr[yy][xx] = 0;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &M, &N, &K);
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);

			arr[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
}
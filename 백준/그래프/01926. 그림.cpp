#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[500][500];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(int y, int x)
{
	int ret = 1;

	queue<pair<int, int>> q;

	q.push({ y,x });
	arr[y][x] = 0;

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == 1) {
					arr[yy][xx] = 0;
					q.push({ yy,xx });
					ret++;
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
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				ans = max(ans,bfs(i, j));
				cnt++;
			}
		}
	}

	printf("%d\n%d", cnt, ans);
}
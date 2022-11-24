#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<pair<int, int>> sw[101][101];
int arr[101][101];
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	scanf("%d %d", &N, &M);
	arr[1][1] = 1;

	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		sw[y][x].emplace_back(b, a);
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 });

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		if (visited[y][x] == 1) continue;
		visited[y][x] = 1;

		for (auto next : sw[y][x]) {
			if (visited[next.first][next.second] == 1) continue;
			arr[next.first][next.second] = 1;
			for (int i = 0; i < 4; i++) {
				const int yy = next.first + dy[i];
				const int xx = next.second + dx[i];
				if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
					if (visited[yy][xx] == 1) {
						q.push({ next.first, next.second });
						break;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == 1) {
					q.push({ yy,xx });
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				ans++;
			}
		}
	}

	printf("%d", ans);
}
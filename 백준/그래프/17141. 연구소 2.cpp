#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int arr[50][50];
vector<pair<int, int>> virus;
int pos[10];
int ans = 987654321;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs()
{
	queue<pair<int, int>>q;
	int ret = 0;
	int cnt = 0;

	int temp[50][50] = { 0 };
	int visited[50][50] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int y = virus[pos[i]].first;
		int x = virus[pos[i]].second;
		q.push({ y,x });
		visited[y][x] = 1;
	}

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		ret = max(ret, temp[y][x]);

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1 && temp[yy][xx] != -1) {
					visited[yy][xx] = 1;
					temp[yy][xx] = temp[y][x] + 1;
					q.push({ yy,xx });
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}

	if (cnt > M) {
		ret = 987654321;
	}

	return ret;
}

void dfs(int level, int n)
{
	if (level == M) {
		ans = min(ans, bfs());
		return;
	}

	for (int i = n; i < virus.size(); i++) {
		pos[level] = i;
		dfs(level + 1, i + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				virus.emplace_back(i, j);
				arr[i][j] = 0;
			}
			else if (arr[i][j] == 1) {
				arr[i][j] = -1;
			}
		}
	}

	dfs(0, 0);

	if (ans == 987654321) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
}
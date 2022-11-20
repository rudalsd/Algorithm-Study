#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int w, h;
char arr[21][21];
int visited[10];
int dist[10][10];	//i부터 j까지 거리
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans;
vector<pair<int, int>> dirt;

struct pos {
	int y;
	int x;
	int cnt;
};

int bfs(int from, int to)	//시작점부터 도착점까지 거리
{
	queue<pos> q;
	int visited[21][21] = { 0 };

	q.push({ dirt[from].first,dirt[from].second,0 });

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		q.pop();

		if (y == dirt[to].first && x == dirt[to].second) {
			return cnt;
		}

		if (visited[y][x] == 1) continue;
		visited[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < h && xx >= 0 && xx < w) {
				if (visited[yy][xx] != 1 && arr[yy][xx] != 'x') {
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	return -1;
}

void dfs(int level, int cur, int hap)	//cur부터 i까지 거리를 hap에 저장
{
	if (ans == -1) return;

	if (level == dirt.size() - 1) {
		ans = min(ans, hap);
		return;
	}

	for (int i = 1; i < dirt.size(); i++) {
		if (visited[i] != 1) {
			visited[i] = 1;
			if (dist[cur][i] == -1) {
				dist[cur][i] = bfs(cur, i);
			}
			dist[i][cur] = dist[cur][i];
			if (dist[cur][i] == -1) {
				ans = -1;
				return;
			}
			hap += dist[cur][i];
			dfs(level + 1, i, hap);
			hap -= dist[cur][i];
			visited[i] = 0;
		}
	}
}

int main()
{
	while (1) {
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) break;

		dirt.clear();
		dirt.emplace_back(0, 0);
		ans = 987654321;
		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < 10; i++) {
			visited[i] = 0;
		}

		for (int i = 0; i < h; i++) {
			scanf("%s", arr[i]);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 'o') {
					dirt[0].first = i;
					dirt[0].second = j;
				}
				if (arr[i][j] == '*') {
					dirt.emplace_back(i, j);
				}
			}
		}

		dfs(0, 0, 0);

		printf("%d\n", ans);
	}
}
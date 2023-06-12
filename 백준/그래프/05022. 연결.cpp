#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int y;
	int x;
	int cnt;
	vector<pair<int, int>> route;
};

int N, M;
int A1x, A1y, A2x, A2y, B1x, B1y, B2x, B2y;
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int Min = 987654321;

int bfs(int y1, int x1, int y2, int x2)
{
	queue<node> q;
	vector<pair<int, int>> temp;
	q.push({ y1,x1,0,temp });
	visited[y1][x1] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		vector<pair<int, int>> temp = q.front().route;
		temp.push_back({ y,x });
		q.pop();

		if (y == y2 && x == x2) {
			for (int i = 0; i <= M; i++) {
				for (int j = 0; j <= N; j++) {
					visited[i][j] = 0;
				}
			}

			for (auto& next : temp) {
				int yyy = next.first;
				int xxx = next.second;
				visited[yyy][xxx] = 1;
			}
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy <= M && xx >= 0 && xx <= N) {
				if (visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx,cnt + 1,temp });
				}
			}
		}
	}

	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);

	scanf("%d %d %d %d %d %d %d %d", &A1x, &A1y, &A2x, &A2y, &B1x, &B1y, &B2x, &B2y);

	visited[B1y][B1x] = 1;
	visited[B2y][B2x] = 1;
	int route1 = bfs(A1y, A1x, A2y, A2x);
	int route2 = bfs(B1y, B1x, B2y, B2x);

	if (route2 != -1) {
		Min = min(Min, route1 + route2);
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			visited[i][j] = 0;
		}
	}

	visited[A1y][A1x] = 1;
	visited[A2y][A2x] = 1;
	route1 = bfs(B1y, B1x, B2y, B2x);
	route2 = bfs(A1y, A1x, A2y, A2x);

	if (route2 != -1) {
		Min = min(Min, route1 + route2);
	}

	if (Min != 987654321) {
		printf("%d", Min);
	}
	else {
		printf("IMPOSSIBLE");
	}
}

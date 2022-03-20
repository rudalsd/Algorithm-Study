#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[50][50];
int tmp[50][50];
int visited[50][50];
int used[10];

struct pos {
	int y;
	int x;
	int cnt;
};

vector<pos> box;
vector<pos>path;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int Min;

int check()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int bfs(queue<pos> q)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
			visited[i][j] = 0;
		}
	}
	int cnt = 0;
	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		int curCnt = q.front().cnt;
		q.pop();

		if (visited[curY][curX] == 1)continue;
		visited[curY][curX] = 1;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (tmp[yy][xx] == 0) {
					q.push({ yy,xx,curCnt + 1 });
					tmp[yy][xx] = curCnt + 1;
					cnt = curCnt + 1;
				}
				if (tmp[yy][xx] == 2) {
					if (check()) {
						return cnt;
					}
					else {
						q.push({ yy,xx,curCnt + 1 });
						tmp[yy][xx] = curCnt + 1;
						cnt = curCnt + 1;
					}
				}
			}
		}
	}

	if (check())
		return cnt;
	else
		return Min;
}

void dfs(int level, int t)
{
	if (Min == 0) return;
	if (level == M)
	{
		queue<pos> q;
		for (int i = 0; i < M; i++) {
			q.push(path[i]);
		}
		int ret = bfs(q);

		if (Min > ret)
		{
			Min = ret;
		}
		return;
	}

	for (int i = t; i < box.size() - M + 1 + level; i++) {
		if (used[i] != 1) {
			used[i] = 1;
			path.push_back(box[i]);
			dfs(level + 1, i + 1);
			path.erase(path.begin() + level);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;
	Min = 9999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				box.push_back({ i,j,0 });
			}
		}
	}

	dfs(0, 0);

	if (Min == 9999999) {
		cout << -1;
	}
	else {
		cout << Min;
	}
}
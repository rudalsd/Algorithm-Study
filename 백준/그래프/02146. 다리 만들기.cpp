#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int y, x, d;
};

int N;
int arr[100][100];
int visited[100][100];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int cnt;
int ans = 987654321;

void bfs(int y, int x)
{
	int v[100][100] = { 0 };
	queue<pair<int, int>> q;
	queue<node> qq;

	q.push({ y,x });

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		arr[y][x] = cnt;

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (arr[yy][xx] == 1 && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
				else if (arr[yy][xx] == 0 && v[y][x] != 1) {
					v[y][x] = 1;
					qq.push({ y,x,0 });
				}
			}
		}
	}

	while (!qq.empty()) {
		const int y = qq.front().y;
		const int x = qq.front().x;
		const int d = qq.front().d;
		qq.pop();

		if (d >= ans) return;

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (arr[yy][xx] == 0 && v[yy][xx] == 0) {
					v[yy][xx] = 1;
					qq.push({ yy,xx,d + 1 });
				}
				else if (arr[yy][xx] != 0 && arr[yy][xx] != cnt) {
					ans = min(ans, d);
					return;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt--;
				bfs(i, j);
			}
		}
	}

	cout << ans;
}
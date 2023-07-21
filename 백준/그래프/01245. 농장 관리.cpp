#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[100][70];
int visited[100][70];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

bool bfs(int y, int x)
{
	bool ret = true;

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == arr[y][x]) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
				else if (arr[yy][xx] > arr[y][x]) {
					ret = false;
				}
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] != 1 && arr[i][j] != 0) {
				if (bfs(i, j)) ans++;
			}
		}
	}

	cout << ans;
}

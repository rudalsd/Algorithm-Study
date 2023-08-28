#include<iostream>
#include<queue>
#include<string>

using namespace std;

int R, C;
string arr[250];
int visited[250][250];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
pair<int, int> ans;

void bfs(int y, int x)
{
	int v = 0, o = 0;

	queue<pair<int, int>> q;

	q.push({ y,x });

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		if (arr[y][x] == 'v') v++;
		else if (arr[y][x] == 'o') o++;

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < R && xx >= 0 && xx < C) {
				if (visited[yy][xx] == 0 && arr[yy][xx] != '#') {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
			}
		}
	}

	if (v >= o) {
		ans.first -= o;
	}
	else {
		ans.second -= v;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'v') {
				ans.second++;
			}
			else if(arr[i][j] == 'o') {
				ans.first++;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == 0 && arr[i][j] != '#') {
				visited[i][j] = 1;
				bfs(i, j);
			}
		}
	}

	cout << ans.first << ' ' << ans.second;
}

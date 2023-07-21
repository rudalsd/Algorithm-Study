#include<iostream>

using namespace std;

int N, M;
char arr[51][51];
int visited[51][51];
int visited2[51][51];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool ans = false;

void dfs(int y, int x, int cnt)
{
	if (ans == true) return;
	visited2[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
			if (arr[yy][xx] == arr[y][x]) {
				if (visited[yy][xx] != 0) {
					if (cnt - visited[yy][xx] + 1 >= 4) {
						ans = true;
						return;
					}
				}
				else {
					visited[yy][xx] = cnt + 1;
					dfs(yy, xx, cnt + 1);
					visited[yy][xx] = 0;
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

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited2[i][j] == 0) {
				visited[i][j] = 1;
				dfs(i, j, 1);
				visited[i][j] = 0;
			}
		}
	}

	if (ans) cout << "Yes";
	else cout << "No";
}
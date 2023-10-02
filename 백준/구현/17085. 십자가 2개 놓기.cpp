#include<iostream>

using namespace std;

int N, M;
char arr[15][16];
int temp[15][15];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
bool flag = false;
int visited[15][15];
int ans;

bool check(int y, int x, int n)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= n; j++) {
			int yy = y + dy[i] * j;
			int xx = x + dx[i] * j;

			if (arr[yy][xx] == '#' && visited[yy][xx] != 1) {
				visited[yy][xx] = 1;
			}
			else {
				return false;
			}
		}
	}

	return true;
}

void dfs(int a, int b, int cnt)
{
	if (flag) return;
	if (cnt == 2) {
		ans = max(ans, (1 + 4 * a) * (1 + 4 * b));
		flag = true;
		return;
	}

	int tmp;

	if (cnt == 0) tmp = a;
	else tmp = b;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = visited[i][j];
		}
	}

	for (int i = tmp; i < N - tmp; i++) {
		for (int j = tmp; j < M - tmp; j++) {
			if (arr[i][j] == '#' && visited[i][j] != 1) {
				visited[i][j] = 1;
				if (check(i, j, tmp)) {
					dfs(a, b, cnt + 1);
				}
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						visited[i][j] = temp[i][j];
					}
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

	for (int i = 7; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			flag = false;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					visited[i][j] = 0;
				}
			}
			dfs(i, j, 0);
		}
	}

	cout << ans;
}
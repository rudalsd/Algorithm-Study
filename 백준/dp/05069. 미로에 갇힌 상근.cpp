#include<iostream>

using namespace std;

int dp[30][30][15];
int dy[] = { -1,0,1,1,0,-1 };
int dx[] = { 0,1,1,0,-1,-1 };
int T, n;

int dfs(int y, int x, int cnt)
{
	if (dp[y][x][cnt] != -1) return dp[y][x][cnt];
	if (cnt == 0) return y == 10 && x == 10;
	int& ret = dp[y][x][cnt];
	ret = 0;

	for (int i = 0; i < 6; i++) {
		const int yy = y + dy[i];
		const int xx = x + dx[i];
		if (yy >= 0 && yy < 30 && xx >= 0 && xx < 30) {
			ret += dfs(yy, xx, cnt - 1);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k <= 14; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	while (T--) {
		cin >> n;

		cout << dfs(10, 10, n) << '\n';
	}
}
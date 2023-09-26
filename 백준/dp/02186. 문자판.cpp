#include<iostream>
#include<string>

using namespace std;

int N, M, K;
string str;
char arr[100][101];
int dp[100][100][80];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int ans;

int dfs(int y, int x, int cnt)
{
	if (cnt == str.size() - 1) {
		return dp[y][x][cnt] = 1;
	}
	if (dp[y][x][cnt] != -1) return dp[y][x][cnt];
	int& ret = dp[y][x][cnt];
	ret = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			const int yy = y + dy[i] * j;
			const int xx = x + dx[i] * j;

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == str[cnt + 1]) {
					ret += dfs(yy, xx, cnt + 1);
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

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 80; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cin >> str;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dp[i][j][0] == -1 && arr[i][j] == str[0]) {
				ans += dfs(i, j, 0);
			}
		}
	}

	cout << ans;
}

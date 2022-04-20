#include <iostream>

using namespace std;

int arr[500][500];
int M, N;
int cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dp[500][500];												//방법의 수를 저장할 dp배열

int dfs(int y, int x) {
	if (dp[y][x] != -1) return dp[y][x];						//이미 방문한 곳이면 dp[y][x]를 리턴
	if (y == M - 1 && x == N - 1) {								//도착하면 1을 리턴
		return 1;
	}

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= 0 && yy < M && xx >= 0 && xx < N) {
			if (arr[yy][xx] < arr[y][x]) {
				dp[y][x] = dp[y][x] + dfs(yy, xx);
			}
		}
	}
	return dp[y][x];
}


int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	dfs(0, 0);

	cout << dp[0][0];
}
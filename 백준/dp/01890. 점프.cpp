#include<iostream>

using namespace std;

int N;
int arr[100][100];
int dy[2] = { 0,1 };
int dx[2] = { 1,0 };
long long dp[100][100];

long long dfs(int y, int x)
{
	if (dp[y][x] != 0) return dp[y][x];
	if (arr[y][x] == 0 && y != N - 1 && x != N - 1) {
		return 0;
	}
	if (y == N - 1 && x == N - 1) return 1;

	for (int i = 0; i < 2; i++) {
		int yy = y + dy[i] * arr[y][x];
		int xx = x + dx[i] * arr[y][x];

		if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
			dp[y][x] += dfs(yy, xx);
		}
	}

	return dp[y][x];
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%lld", dfs(0, 0));
}
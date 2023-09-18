#include<iostream>

using namespace std;

int n;
int arr[500][500];
int dp[500][500];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans;

int dfs(int y, int x)
{
	int& ret = dp[y][x];
	if (ret != 0) return ret;
	ret = 1;
	
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (yy >= 0 && yy < n && xx >= 0 && xx < n) {
			if (arr[yy][xx] > arr[y][x]) {
				ret = max(ret, dfs(yy, xx) + 1);
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans,dfs(i, j));
		}
	}

	printf("%d", ans);
}

#include <iostream>

using namespace std;

int arr[500][500];
int M, N;
int cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dp[500][500];												//����� ���� ������ dp�迭

int dfs(int y, int x) {
	if (dp[y][x] != -1) return dp[y][x];						//�̹� �湮�� ���̸� dp[y][x]�� ����
	if (y == M - 1 && x == N - 1) {								//�����ϸ� 1�� ����
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
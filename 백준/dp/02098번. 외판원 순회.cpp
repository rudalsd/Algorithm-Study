#include<iostream>
#include<cstring>

using namespace std;

int N;
int arr[16][16];
int dp[16][(1 << 16)];
int visitedAll;

int dfs(int node, int via)
{
	if (via == visitedAll) {
		if (arr[node][0] == 0) return 987654321;
		return arr[node][0];
	}

	if (dp[node][via] != -1) return dp[node][via];	//�湮�� �� �ִٸ� dp[vode][via]���
	dp[node][via] = 987654321;			//�ƴҰ��

	for (int i = 0; i < N; i++) {
		if (via & (1 << i)) continue;	//�̹� �湮
		if (arr[node][i] == 0) continue;	//���� ���ٸ�
		dp[node][via] = min(dp[node][via], arr[node][i] + dfs(i, via | (1 << i)));
	}
	return dp[node][via];
}

int main()
{
	cin >> N;

	visitedAll = (1 << N) - 1;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = dfs(0, 1);

	cout << ans;
}
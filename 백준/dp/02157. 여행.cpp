#include<iostream>

using namespace std;

int N, M, K;
int list[301][301];		//i���� j���� �⳻�� ���
int dp[301][301];		//1�� ���ÿ��� i�� ���ñ��� j�� �̵����� ���� �ִ�

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		if (a < b) {
			list[a][b] = max(list[a][b], cost);
		}
	}

	for (int i = 2; i <= N; i++) {	//1�� ���ÿ��� �ٸ� ���÷� ���� ���
		if (list[1][i] != 0) {
			dp[i][2] = max(dp[i][2], list[1][i]);
		}
	}

	for (int i = 2; i < M; i++) { //2�� �̵��� ���ĺ��� ���
		for (int j = 1; j <= N; j++) {
			if (dp[j][i] != 0) {
				for (int k = j + 1; k <= N; k++) {
					if (list[j][k] != 0) {
						dp[k][i + 1] = max(dp[k][i + 1], dp[j][i] + list[j][k]);
					}
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= M; i++) {
		ans = max(ans, dp[N][i]);
	}

	printf("%d", ans);
}
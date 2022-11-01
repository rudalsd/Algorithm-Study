#include<iostream>

using namespace std;

int N, M;
int m[10001];
int dp[10001][150];

int go(int cur, int x)
{
	if (cur == N) return 0;

	int& ret = dp[cur][x];
	if (ret != 0) return ret;

	ret = 987654321;

	for (int i = -1; i < 2; i++) {
		int xx = x + i;

		if (xx > 0 && cur + xx <= N && m[cur + xx] != 1) {
			ret = min(ret, go(cur + xx, xx) + 1);
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		m[num] = 1;

		if (m[2] == 1) {
			printf("%d", -1);
			return 0;
		}
	}

	go(1, 0);

	if (dp[1][0] == 987654321) {
		printf("%d", -1);
	}
	else {
		printf("%d", dp[1][0]);
	}
}
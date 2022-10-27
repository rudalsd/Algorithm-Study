#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int N, M;
int o1, o2;
int arr[20];
int dp[20][21][21];	//[순서][1번문][2번분]

int go(int num, int o1, int o2)
{
	if (num >= M) {
		return 0;
	}
	if (dp[num][o1][o2] != -1) {
		return dp[num][o1][o2];
	}
	int& ret = dp[num][o1][o2];
	ret = min(abs(arr[num] - o1) + go(num + 1, arr[num], o2), abs(arr[num] - o2) + go(num + 1, o1, arr[num]));
	return ret;
}

int main()
{
	scanf("%d %d %d %d", &N, &o1, &o2, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
	}

	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, o1, o2));
}
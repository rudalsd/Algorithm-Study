#include<iostream>

using namespace std;

int N;
int arr[301];
int dp[3][301];

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1][1] = arr[1];

	for (int i = 2; i <= N; i++) {
		dp[1][i] = max(dp[2][i - 2], dp[1][i - 2]) + arr[i];	//계단을 연속으로 한번 밟는 경우
		dp[2][i] = dp[1][i - 1] + arr[i];	//계단을 연속으로 두번 밟는 경우
	}

	printf("%d", max(dp[1][N], dp[2][N]));
}
#include <iostream>
#include <cstring>

using namespace std;

int N;

struct Matrix {
	int r;
	int c;
};

Matrix arr[550];
int dp[550][550];																//dp[start][end], start부터 end까지 최솟값을 저장할 dp배열

unsigned int DP(int start, int end)												//start부터 end까지의 최숫값을 return할 DP함수
{
	if (start == end) return 0;													//같으면 return 0;
	if (dp[start][end] != -1) return dp[start][end];							//한번이라도 최솟값을 찾아냈으면 return dp[start][end]
	if (end - start == 1) return arr[start].r * arr[start].c * arr[end].c;		//한 칸 차이라면 두 행열의 곱 return

	int Min = 2147483647;														//2^31 -1

	for (int i = start; i <= end - 1; i++) {
		int sum = DP(start, i) + DP(i + 1, end);								//특정 구역의 행열 곱 최솟값들을 더하고
		sum += arr[start].r * arr[i].c * arr[end].c;							//그 구역 의 처음과 끝의 행열 곱을 더해준 뒤
		Min = min(sum, Min);													//최솟값을 Min에 저장
	}
	dp[start][end] = Min;														//구역 내 최솟값을 dp[start][end]에 저장
	return Min;
}

int main()
{
	cin >> N;
	int Min = 2147483647;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> arr[i].r >> arr[i].c;
	}

	for (int i = 0; i < N - 1; i++) {
		int sum = DP(0, i) + DP(i + 1, N - 1);										//모든 구역을 이분해서 각 구역의 최솟값을 sum에 넣고,
		sum += arr[0].r * arr[i].c * arr[N - 1].c;								//처음과 끝 행열의 곱을 sum에 넣은 뒤
		Min = min(sum, Min);													//최솟값을 Min에 저장
	}

	cout << Min;
}
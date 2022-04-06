#include <iostream>

using namespace std;

int main()
{
	long long dp[1010] = { 0 };					//값을 저장할 배열 생성
	int n;

	cin >> n;

	dp[1] = 1;									//첫번째 배열 1로 저장
	dp[2] = 2;									//두번째 배열 2로 저장

	if (n < 3) {								//n이 3보다 작을 때는 바로 출력
		cout << dp[n];
		return 0;
	}
	else {
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];		//점화식
			dp[i] %= 10007;						//10007로 나눈 나머지 값 저장
		}
	}

	cout << dp[n];								//n번째 값 출력
}
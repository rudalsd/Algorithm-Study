#define MAX 987654321

#include <iostream>

using namespace std;

int N;

int arr[3][1001];																			//각 색의 가격을 저장할 배열
int dp[3][1001];																			//각 색을 칠했을 때의 총 가격

int main()
{
	cin >> N;
	int ans = MAX;
	for (int i = 1; i <= N; i++) {
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	}

	for (int i = 0; i < 3; i++)																//첫 집의 색깔을 졍해주기
	{
		for (int j = 0; j < 3; j++) {
			if (i == j) dp[j][1] = arr[j][1];												//첫 집의 색만 가격 입력
			else dp[j][1] = MAX;															//나머지 색은 가격 MAX
		}																					//다음 집에서 첫 집의 색을 고르지 못하도록 하기 위해서

		for (int j = 2; j <= N; j++) {
			dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + arr[0][j];							//앞의 집의 색 중 가격이 싼 색의 값과 지금 집 색의 값을 더함
			dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + arr[1][j];
			dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + arr[2][j];
		}

		for (int j = 0; j < 3; j++) {
			if (i != j) {																	//마지막 집이 첫 집과 색이 같으면 안되기 때문에 i!=j 조건 넣기
				ans = min(ans, dp[j][N]);
			}
		}
	}

	cout << ans;
}
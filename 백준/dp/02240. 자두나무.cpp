#include <iostream>

using namespace std;

int T, W;
int cur;
int arr[1100];									//각 시간에 자두가 떨어질 나무 저장할 arr배열
int dp[3][40][1100];							//각 시간마다 자두를 먹을 수 있는 최대 개수 저장할 dp배열

int main()
{
	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i <= W; i++) {
		for (int j = 1; j <= T; j++) {
			if (i % 2 == 0) {					//움직인 횟수가 짝수일 때
				dp[1][i][j] = max(dp[1][i][j - 1] + (arr[j] == 1), dp[2][i - 1][j - 1] + (arr[j] == 1));
			}
			else {								//움직인 횟수가 홀수일 때
				dp[2][i][j] = max(dp[2][i][j - 1] + (arr[j] == 2), dp[1][i - 1][j - 1] + (arr[j] == 2));
			}
		}
	}
	//만약 1번 나무에 서있다면 '움직인 횟수는 똑같은 전 시간'의 dp배열의 값과 '움직이 횟수가 1 적은 전 시간의 2번 나무' dp배열과 비교
	//만약 2번 나무에 서있다면 '움직인 횟수는 똑같은 전 시간'의 dp배열의 값과 '움직이 횟수가 1 적은 전 시간의 1번 나무' dp배열과 비교

	int max = 0;

	for (int i = 0; i <= W; i++) {
		if (max < dp[1][i][T]) {
			max = dp[1][i][T];
		}
		if (max < dp[2][i][T]) {
			max = dp[2][i][T];
		}
	}

	cout << max;
}
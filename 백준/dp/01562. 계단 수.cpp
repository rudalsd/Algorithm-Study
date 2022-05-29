#include <iostream>

using namespace std;

int N;
long long dp[10][101][4];				//각 숫자가 들어갈 수 있는 개수를 저장할 배열
										//1 : 0과 닿음, 2 : 9와 닿음, 3 : 0, 9와 닿음
int main()
{
	cin >> N;

	long long cnt = 0;					//총 개수를 저장할 변수

	for (int i = 1; i < 9; i++) {		//N이 1일 때 0을 제외한 각 숫자가 한번씩 들어갈 수 있으므로
		dp[i][1][0] = 1;				//모두 1로 경신
	}

	dp[9][1][2] = 1;

	for (int i = 2; i <= N; i++) {		//2자릿수 부터 돌면서
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 4; k++) {
				if (j == 0) {			//0과 닿아있으면 k|1에 그 전의 모든 값들을 더함
					dp[j][i][k | 1] += dp[1][i - 1][k];
					dp[j][i][k | 1] %= 1000000000;
				}
				else if (j == 9) {		//9와 닿아있으면 k|2에 그 전의 모든 값들을 더함
					dp[j][i][k | 2] += dp[8][i - 1][k];
					dp[j][i][k | 2] %= 1000000000;
				}
				else {					//아니라면 전의 값들 중 계단수들의 값들을 더함
					dp[j][i][k] = dp[j - 1][i - 1][k] + dp[j + 1][i - 1][k];
					dp[j][i][k] %= 1000000000;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cnt += dp[i][N][3];
		cnt %= 1000000000;
	}

	cout << cnt;
}
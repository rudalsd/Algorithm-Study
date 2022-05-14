#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];												//S, E가 팰린드롬이라면 1 아니라면 0

int N, M;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i][i] = 1;											//S, E가 같다면 dp = 1
	}
	cin >> M;

	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (j - i == 1) {									//차이가 1이라면 두 수가 서로 같을 때 dp = 1
				if (arr[i] == arr[j]) {
					dp[i][j] = 1;
				}
			}
			else {												//아니라면
				if (dp[i + 1][j - 1] == 1) {					//dp[i+1][j-1]이 1일 때 두 수가 같으면 dp = 1
					if (arr[i] == arr[j]) {
						dp[i][j] = 1;
					}
				}
			}

		}
	}

	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S - 1][E - 1]);
	}
}
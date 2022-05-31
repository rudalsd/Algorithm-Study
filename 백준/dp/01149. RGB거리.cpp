#include <iostream>
#define INF 987654321

using namespace std;

int N;
int RGB[1000][3];		//비용을 저장할 배열
int dp[1000][3];		//최솟값을 저장할 배열

int main()
{
	cin >> N;
	int ans = INF;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
	}

	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == t && j == 0) {
					dp[j][i] = RGB[0][i];	//첫 집의 색을 정함
				}
				else {
					dp[i][j] = INF;			//나머지 집은 INF로 초기화
				}
			}
		}

		for (int i = 1; i < N; i++) {		//각 색깔로 칠했을 때 최솟값을 dp에 저장
			dp[i][0] = min(dp[i - 1][1] + RGB[i][0], dp[i - 1][2] + RGB[i][0]);
			dp[i][1] = min(dp[i - 1][0] + RGB[i][1], dp[i - 1][2] + RGB[i][1]);
			dp[i][2] = min(dp[i - 1][0] + RGB[i][2], dp[i - 1][1] + RGB[i][2]);
		}

		for (int i = 0; i < 3; i++) {		//마지막에 세 집 중 가장 비용이 적은 집 ans에 저장
			if (ans > dp[N - 1][i]) {
				ans = dp[N - 1][i];
			}
		}
	}

	cout << ans;
}
#include <iostream>

using namespace std;

int N, M;
int b[110];																		//앱의 byte를 저장할 배열
int c[110];																		//앱의 비용을 저장할 배열
int dp[110][10010];																//앱 비활성화 시 얻는 byte를 저장할 배열

int main()
{
	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];															//최대 비용을 계산
	}

	int min = 987654321;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j >= c[i]) {													//지금 비용을 감당 가능할 때
				dp[i][j] = max(b[i] + dp[i - 1][j - c[i]], dp[i - 1][j]);
			}
			else {																//지금 비용을 감당할 수 없을 때
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= M) {
				if (min > j) {
					min = j;
				}
				break;
			}
		}
	}

	cout << min;
}
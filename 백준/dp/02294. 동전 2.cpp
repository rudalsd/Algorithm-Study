#include <iostream>

using namespace std;

int dp[10100];
int coin[110];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		dp[i] = 987654321;								//최솟값을 찾기 위해 dp배열을 987654321로 초기화
	}

	for (int i = 0; i < n; i++) {
		cin >> coin[i];									//동전의 가격을 coin배열에 저장
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i + coin[j] < 10100) {					//배열의 크기를 넘어서지 않는 선에서 최솟값을 저장
				if (dp[i + coin[j]] > dp[i] + 1) {		//dp배열의 i+coin[j]번째 배열의 값보다 i번째 배열의 값 + 1이 더 작은 경우 값을 갱신
					dp[i + coin[j]] = dp[i] + 1;
				}
			}
		}
	}

	if (dp[k] == 987654321) {							//배열이 갱신될 수 없으면 -1출력
		cout << -1;
	}
	else {
		cout << dp[k];									//dp배열의 k번째 값을 출력
	}
}
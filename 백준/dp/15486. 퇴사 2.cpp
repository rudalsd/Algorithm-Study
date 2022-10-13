#include<iostream>

using namespace std;

int N;
int dp[1500001];	//각 날에 벌 수 있는 최대 금액을 저장할 dp배열
pair<int, int> arr[1500001];	//각 날의 정보를 저장할 배열

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int t, p;
		scanf("%d %d", &t, &p);
		arr[i] = { t,p };
	}

	int Max = 0;

	for (int i = 0; i <= N; i++) {
		int t = arr[i].first;
		int p = arr[i].second;
		Max = max(dp[i], Max);
		if (dp[i] < Max) {
			dp[i] = Max;
		}
		if (i + t > N) continue;
		if (dp[i + t] < dp[i] + p) {
			dp[i + t] = dp[i] + p;
		}
	}

	printf("%d", Max);
}
#include<iostream>

using namespace std;

int N;
int dp[1500001];	//�� ���� �� �� �ִ� �ִ� �ݾ��� ������ dp�迭
pair<int, int> arr[1500001];	//�� ���� ������ ������ �迭

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
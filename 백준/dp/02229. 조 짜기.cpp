#include<iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];	//i�� �л����� �� ¥���� ������ �ִ�

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 2; i <= N; i++) {
		int Max = arr[i];
		int Min = arr[i];

		for (int j = i - 1; j > 0; j--) {
			Max = max(Max, arr[j]);
			Min = min(Min, arr[j]);

			dp[i] = max(dp[i], dp[j - 1] + Max - Min);
			//j ~ i ������ �ִ񰪰� �ּڰ��� ���� dp[j - 1]�� ��
		}
	}

	printf("%d", dp[N]);
}
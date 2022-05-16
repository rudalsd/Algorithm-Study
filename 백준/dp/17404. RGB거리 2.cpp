#define MAX 987654321

#include <iostream>

using namespace std;

int N;

int arr[3][1001];																			//�� ���� ������ ������ �迭
int dp[3][1001];																			//�� ���� ĥ���� ���� �� ����

int main()
{
	cin >> N;
	int ans = MAX;
	for (int i = 1; i <= N; i++) {
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	}

	for (int i = 0; i < 3; i++)																//ù ���� ������ �����ֱ�
	{
		for (int j = 0; j < 3; j++) {
			if (i == j) dp[j][1] = arr[j][1];												//ù ���� ���� ���� �Է�
			else dp[j][1] = MAX;															//������ ���� ���� MAX
		}																					//���� ������ ù ���� ���� ���� ���ϵ��� �ϱ� ���ؼ�

		for (int j = 2; j <= N; j++) {
			dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + arr[0][j];							//���� ���� �� �� ������ �� ���� ���� ���� �� ���� ���� ����
			dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + arr[1][j];
			dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + arr[2][j];
		}

		for (int j = 0; j < 3; j++) {
			if (i != j) {																	//������ ���� ù ���� ���� ������ �ȵǱ� ������ i!=j ���� �ֱ�
				ans = min(ans, dp[j][N]);
			}
		}
	}

	cout << ans;
}
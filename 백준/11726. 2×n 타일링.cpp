#include <iostream>

using namespace std;

int main()
{
	long long dp[1010] = { 0 };					//���� ������ �迭 ����
	int n;

	cin >> n;

	dp[1] = 1;									//ù��° �迭 1�� ����
	dp[2] = 2;									//�ι�° �迭 2�� ����

	if (n < 3) {								//n�� 3���� ���� ���� �ٷ� ���
		cout << dp[n];
		return 0;
	}
	else {
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];		//��ȭ��
			dp[i] %= 10007;						//10007�� ���� ������ �� ����
		}
	}

	cout << dp[n];								//n��° �� ���
}
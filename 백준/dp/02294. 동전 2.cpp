#include <iostream>

using namespace std;

int dp[10100];
int coin[110];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		dp[i] = 987654321;								//�ּڰ��� ã�� ���� dp�迭�� 987654321�� �ʱ�ȭ
	}

	for (int i = 0; i < n; i++) {
		cin >> coin[i];									//������ ������ coin�迭�� ����
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i + coin[j] < 10100) {					//�迭�� ũ�⸦ �Ѿ�� �ʴ� ������ �ּڰ��� ����
				if (dp[i + coin[j]] > dp[i] + 1) {		//dp�迭�� i+coin[j]��° �迭�� ������ i��° �迭�� �� + 1�� �� ���� ��� ���� ����
					dp[i + coin[j]] = dp[i] + 1;
				}
			}
		}
	}

	if (dp[k] == 987654321) {							//�迭�� ���ŵ� �� ������ -1���
		cout << -1;
	}
	else {
		cout << dp[k];									//dp�迭�� k��° ���� ���
	}
}
#include <iostream>

using namespace std;

int N, M;
int b[110];																		//���� byte�� ������ �迭
int c[110];																		//���� ����� ������ �迭
int dp[110][10010];																//�� ��Ȱ��ȭ �� ��� byte�� ������ �迭

int main()
{
	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];															//�ִ� ����� ���
	}

	int min = 987654321;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j >= c[i]) {													//���� ����� ���� ������ ��
				dp[i][j] = max(b[i] + dp[i - 1][j - c[i]], dp[i - 1][j]);
			}
			else {																//���� ����� ������ �� ���� ��
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
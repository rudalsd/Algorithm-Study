#include <iostream>
#include <string>

using namespace std;

string str;

int dp[2501][2501];					//�Ӹ�������� �Ǻ��� �迭
int ans[2501];						//�ּڰ��� ������ �迭

int main()
{
	cin >> str;
	str = ' ' + str;
	for (int i = str.size(); i >= 1; i--) {		//dp[start][end] start���� end���� �Ӹ�����̶�� 1 �ƴ϶�� 0
		for (int j = str.size(); j >= i; j--) {
			if (i == j) dp[i][j] = 1;
			else if (j - i == 1) {
				if (str[i] == str[j]) {
					dp[i][j] = 1;
				}
			}
			else {
				if (dp[i + 1][j - 1] == 1) {
					if (str[i] == str[j]) {
						dp[i][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 1; i <= str.size() - 1; i++) {
		ans[i] = 3000;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i] == 1) {				//j���� i���� �Ӹ�����̶�� j-1�� ������ 1 �� ũ�Ƿ�
				ans[i] = min(ans[i], ans[j - 1] + 1);
			}									//������ ������ �Ǿ��ִ� ���� �� ���� ���� �����Ƿ�
		}										//���� ���ؼ� �� ���� ���� ����
	}


	cout << ans[str.size() - 1];
}
#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
	string str[2];

	for (int i = 0; i < 2; i++) {
		cin >> str[i];
		str[i] = '0' + str[i];		//������ 1���� �����ϱ� ���ؼ� �� �տ� ���� ���ڸ� ����
	}

	for (int i = 1; i < str[0].size(); i++) {
		for (int j = 1; j < str[1].size(); j++) {	//�� ���ڵ��� ���ϸ� ���� �κм����� ���̸� ���
			if (str[0][i] == str[1][j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str[0].size() - 1][str[1].size() - 1];
}
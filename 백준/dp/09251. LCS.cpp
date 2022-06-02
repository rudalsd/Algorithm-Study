#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
	string str[2];

	for (int i = 0; i < 2; i++) {
		cin >> str[i];
		str[i] = '0' + str[i];		//수열을 1부터 시작하기 위해서 맨 앞에 더미 문자를 넣음
	}

	for (int i = 1; i < str[0].size(); i++) {
		for (int j = 1; j < str[1].size(); j++) {	//각 문자들을 비교하며 최장 부분수열의 길이를 경신
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
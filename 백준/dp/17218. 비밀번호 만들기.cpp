#include<iostream>
#include<string>

using namespace std;

string str1, str2;
int dp[41][41];

int main()
{
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int i = str1.size();
	int j = str2.size();
	string ans;

	while (1) {
		if (dp[i][j - 1] == dp[i][j] - 1 && dp[i - 1][j] == dp[i][j] - 1 && dp[i-1][j-1] == dp[i][j]-1) {
			ans = str1[i - 1] + ans;
			i--;
			j--;
		}
		else if (dp[i][j - 1] == dp[i][j] - 1 && dp[i - 1][j] == dp[i][j]) {
			i--;
		}
		else if (dp[i][j - 1] == dp[i][j] && dp[i - 1][j] == dp[i][j] - 1) {
			j--;
		}
		else {
			i--;
			j--;
		}

		if (i == 0 || j == 0) break;
	}

	cout << ans;
}
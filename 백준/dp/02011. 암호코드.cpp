#include<iostream>
#include<string>
#define M 1000000

using namespace std;

string str;
int dp[3][5001];

int main()
{
	cin >> str;

	if (str[0] == '0') {
		printf("%d", 0);
		return 0;
	}

	for (int i = 0; i < 2; i++) {	//초기 세팅
		if (str[i] != '0') dp[1][i] = 1;
	}
	if ((str[0] - '0') * 10 + str[1] - '0' > 0 && (str[0] - '0') * 10 + str[1] - '0' < 27) {
		dp[2][1] = 1;
	}

	for (int i = 2; i < str.size(); i++) {
		if (((str[i - 1] - '0') * 10 + str[i] - '0' > 26 && str[i] != '0') || (str[i - 1] == '0' && str[i] > '0')) {
			dp[1][i] = (dp[1][i - 1] % M + dp[2][i - 1] % M) % M;
		} // 27이상이고 1의 자리가 0이 아닐 때 또는 10의 자리가 0이고 1의 자리가 0이 아닐 때
		else if (str[i] == '0') {
			if (str[i - 1] != '1' && str[i - 1] != '2') {	//10, 20이 아닐 때
				printf("%d", 0);
				return 0;
			}
			else {	//10, 20일 때
				dp[2][i] = (dp[1][i - 2] % M + dp[2][i - 2] % M) % M;
			}
		}
		else {	//11이상 26이하일 때
			dp[1][i] = (dp[1][i - 1] % M + dp[2][i - 1] % M) % M;
			dp[2][i] = (dp[1][i - 2] % M + dp[2][i - 2] % M) % M;
		}
	}

	printf("%d", (dp[1][str.size() - 1] % M + dp[2][str.size() - 1] % M) % M);
}
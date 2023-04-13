#include<iostream>

using namespace std;

char ans[21];
char arr[2][101];
int dp[2][21][101];
int lenAns, lenArr;

int main()
{
	scanf("%s", ans);

	scanf("%s %s", arr[0], arr[1]);

	for (int i = 0; i < 21; i++) {
		if (ans[i] == 0) {
			lenAns = i;
			break;
		}
	}

	for (int i = 0; i < 101; i++) {
		if (arr[0][i] == 0) {
			lenArr = i;
			break;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < lenAns; j++) {
			for (int k = 0; k < lenArr; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < lenArr; i++) {
		if (arr[0][i] == ans[0]) {
			dp[0][0][i] = 1;
		}
		if (arr[1][i] == ans[0]) {
			dp[1][0][i] = 1;
		}
	}

	for (int i = 1; i < lenAns; i++) {
		for (int j = i; j < lenArr; j++) {
			if (arr[0][j] == ans[i]) {
				int temp = 0;
				for (int k = 0; k < j; k++) {
					if (dp[1][i - 1][k] != -1) {
						temp += dp[1][i - 1][k];
					}
				}
				dp[0][i][j] = temp;
			}
			if (arr[1][j] == ans[i]) {
				int temp = 0;
				for (int k = 0; k < j; k++) {
					if (dp[0][i - 1][k] != -1) {
						temp += dp[0][i - 1][k];
					}
				}
				dp[1][i][j] = temp;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < lenArr; i++) {
		if (dp[0][lenAns - 1][i] != -1) {
			ans += dp[0][lenAns - 1][i];
		}
		if (dp[1][lenAns - 1][i] != -1) {
			ans += dp[1][lenAns - 1][i];
		}
	}

	printf("%d", ans);
}
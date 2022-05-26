#include <iostream>
#include <string>

using namespace std;

string str;

int dp[2501][2501];					//팰린드롬인지 판별할 배열
int ans[2501];						//최솟값을 저장할 배열

int main()
{
	cin >> str;
	str = ' ' + str;
	for (int i = str.size(); i >= 1; i--) {		//dp[start][end] start부터 end까지 팰린드롬이라면 1 아니라면 0
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
			if (dp[j][i] == 1) {				//j부터 i까지 팰린드롬이라면 j-1의 값보다 1 더 크므로
				ans[i] = min(ans[i], ans[j - 1] + 1);
			}									//하지만 갱신이 되어있는 값이 더 작을 수도 있으므로
		}										//둘을 비교해서 더 작은 값을 대입
	}


	cout << ans[str.size() - 1];
}
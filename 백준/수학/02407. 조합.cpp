#include <iostream>
#include <string>

using namespace std;

string dp[101][101];

string sum(string a, string b)				//a와 b를 더해주는 함수
{
	string ans = "";

	int lenA = a.size();
	int lenB = b.size();
	int len = max(lenA, lenB);
	int sum = 0;
	char num;

	while (lenB != len) {
		b = '0' + b;
		lenB++;
	}
	while (lenA != len) {
		a = '0' + a;
		lenA++;
	}

	for (int i = len - 1; i >= 0; i--) {
		sum = a[i] + b[i] - '0' - '0' + sum;
		num = sum % 10 + '0';
		ans = num + ans;
		sum /= 10;
	}
	if (sum != 0) {
		ans = (char)(sum + '0') + ans;
	}


	return ans;
}

string change(int num)						//특정 int를 string의 형태로 바꿔주는 함수
{
	string ans = "";
	if (num > 99) {
		ans = "100";
	}
	else if (num > 9) {
		ans += (char)(num / 10 + '0');
		ans += (char)(num % 10 + '0');
	}
	else {
		ans = (char)(num + '0');
	}

	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++) {
		dp[i][1] = change(i);
	}


	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j) {					//n과 m이 같을 때는 1이므로
				dp[i][j] = "1";
			}
			else {							//아닐 때는 nCm = n-1Cm-1 + n-1Cm을 대입
				dp[i][j] = sum(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[n][m];
}
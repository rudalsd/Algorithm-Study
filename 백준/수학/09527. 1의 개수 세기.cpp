#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long A, B;
long long dp[56];

long long cnt(long long num)
{
	vector<int> bin;

	long long temp = num;
	long long sum = 0;

	while (temp != 0) {
		bin.push_back(temp % 2);
		temp /= 2;
	}

	for (int i = bin.size() - 1; i >= 0; i--) {
		if (bin[i] == 1) {
			sum += dp[i] + num - ((long long)1 << i) + 1;			//num - 1<<i + 1 의 개수만큼 1이 더 있으므로
			num -= ((long long)1 << i);
		}
	}

	return sum;
}

int main()
{
	cin >> A >> B;
	for (int i = 1; i <= 55; i++) {
		dp[i] = dp[i - 1] * 2 + ((long long)1 << i - 1);				//점화식
	}

	cout << cnt(B) - cnt(A - 1);
}
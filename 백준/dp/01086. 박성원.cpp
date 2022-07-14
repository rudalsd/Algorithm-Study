#include<iostream>
#include<string>
#include<cstring>

#define ll long long

using namespace std;

int N, K;
string arr[16];
ll dp[1 << 15][100];
int mods[15];
int digit[51];

ll GCD(ll a, ll b)		//최대 공약수 구하기
{
	while (a != 0) {
		ll temp = b % a;
		b = a;
		a = temp;
	}

	return b;
}

int mod(string num)		//입력된 숫자를 K로 나눈 나머지 구하기
{
	int ret = 0;

	for (int i = 0; i < num.size(); i++) {
		ret = (ret * 10) % K + (num[i] - '0') % K;
		ret %= K;
	}

	return ret;
}

ll Fac(int num)		//팩토리얼
{
	ll ret = 1;

	for (int i = 1; i <= num; i++) {
		ret *= i;
	}

	return ret;
}

ll DP(int cur, int mod)		//나머지별로 개수 저장
{
	if (cur == (1 << N) - 1) {	//모든 수를 썼는가?
		if (mod == 0) return 1;
		else return 0;
	}

	ll& ret = dp[cur][mod];

	if (ret != -1) return dp[cur][mod];	//사용된 적이 있는가?

	ret = 0;

	for (int i = 0; i < N; i++) {
		int mask = 1 << i;

		if (cur & mask) continue;		//이미 사용된 숫자면 continue

		ret += DP(cur | mask, ((mod * digit[arr[i].size()]) % K + mods[i]) % K);
	}

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	digit[0] = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> K;

	for (int i = 0; i < N; i++) {
		mods[i] = mod(arr[i]);
	}

	for (int i = 1; i <= 50; i++) {
		digit[i] = ((digit[i - 1] % K) * (10 % K)) % K;
	}

	ll numerator = DP(0, 0);	//분자
	ll denominator = Fac(N);	//분모
	if (numerator == 0) {
		cout << "0/1";
		return 0;
	}

	if (numerator == denominator) {
		cout << "1/1";
		return 0;
	}

	ll gcd = GCD(numerator, denominator);

	cout << numerator / gcd << "/" << denominator / gcd;
}
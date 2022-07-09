#include<iostream>

#define ll long long

using namespace std;

ll n;
ll ans;

int main()
{
	cin >> n;
	ans = n;

	for (ll i = 2; i * i <= n; i++) {
		int cnt = 0;
		bool flag = false;
		while (n % i == 0) {		//소인수분해
			n /= i;
			flag = true;
		}

		if (flag) {		//오일러 피
			ans = ans - ans / i;
		}
	}

	if (n != 1) {		//남은 n이 소수라면
		ans = ans - ans / n;
	}

	cout << ans;
}
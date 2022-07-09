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
		while (n % i == 0) {		//���μ�����
			n /= i;
			flag = true;
		}

		if (flag) {		//���Ϸ� ��
			ans = ans - ans / i;
		}
	}

	if (n != 1) {		//���� n�� �Ҽ����
		ans = ans - ans / n;
	}

	cout << ans;
}
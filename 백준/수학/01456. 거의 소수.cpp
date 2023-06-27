#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll A, B;
int arr[10000001];
vector<ll> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	for (ll i = 2; i * i <=B; i++) {
		if (!arr[i]) {
			prime.push_back(i);
			for (int j = 2; i * j * i * j <= B; j++) {
				arr[i * j] = 1;
			}
		}
	}

	int ans = 0;

	for (ll i : prime) {
		if (!arr[i]) {
			ll temp = 1LL * i;
			while(1){
				temp *= 1LL * i;
				if (temp > B || temp % i != 0) break;
				if (temp < A) continue;
				ans++;
			}
		}
	}

	cout << ans;
}

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int n, s;
vector<int> arr;

bool check(int m)
{
	int tmp = arr[0];
	int cnt = 1;
	while (1) {
		auto it = lower_bound(arr.begin(), arr.end(), tmp + m);
		if (it == arr.end()) break;
		tmp = *it;
		cnt++;
	}

	if (cnt >= s) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> n >> s;

		arr.clear();

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}

		sort(arr.begin(), arr.end());

		int a, b;
		a = 0;
		b = 1000000000;
		int ans = 0;

		while (a < b) {
			int m = (a + b) / 2;

			if (check(m)) {
				ans = m;
				a = m + 1;
			}
			else {
				b = m;
			}
		}

		cout << ans << '\n';
	}
}

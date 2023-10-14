#include<iostream>
#include<cmath>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;

		int dif = y - x;
		int tmp = (int)sqrt(dif);

		int ans = tmp * 2 - 1;

		if (dif == 0) {
			cout << 0 << '\n';
		}
		else {
			if (dif - tmp * tmp != 0) {
				ans++;
				if ((double)tmp + 0.5f < sqrt(dif)) {
					ans++;
				}
			}

			cout << ans << '\n';
		}
	}
}
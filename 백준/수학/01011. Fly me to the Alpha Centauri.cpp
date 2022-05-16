#include <iostream>
#include <math.h>

using namespace std;

long long x, y;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> x >> y;
		long long m = y - x;

		long long k = (int)sqrt(m);

		if (k * k == m) {
			cout << 2 * k - 1 << endl;
		}
		else if (k % 2 == 0) {
			if (k * k < m && k * k + k >= m) {
				cout << 2 * k << endl;
			}
			else if (k * k + 2 < m && (k + 1) * (k + 1) >= m) {
				cout << 2 * k + 1 << endl;
			}
		}
		else if (k % 2 == 1) {
			if (k * k < m && k * k + k >= m) {
				cout << 2 * k << endl;
			}
			else if (k * k + k < m && (k + 1) * (k + 1) >= m) {
				cout << 2 * k + 1 << endl;
			}
		}
	}
}
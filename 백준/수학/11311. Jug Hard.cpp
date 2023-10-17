#include<iostream>

using namespace std;

int T;
int a, b, d;

int euclid(int a, int b)
{
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> a >> b >> d;

		if (a >= d || b >= d) {
			int tmp = euclid(a, b);

			if (d % tmp == 0) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
		}
		else {
			cout << "No";
		}
		cout << '\n';
	}
}

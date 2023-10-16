#include<iostream>

using namespace std;

int T;
int a, b, c;

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
		cin >> a >> b >> c;

		if (a >= c || b >= c) {
			int tmp = euclid(a, b);

			if (c % tmp == 0) {
				cout << "YES";
			}
			else{
				cout << "NO";
			}
		}
		else {
			cout << "NO";
		}

		cout << '\n';
	}
}

#include<iostream>
#include<string>

using namespace std;

int T;
bool erase;

bool check(string str, int num)
{
	int s = 0, e = str.size() - 1;

	while (s < e) {
		if (str[s] == str[e]) {
			s++;
			e--;
		}
		else {
			if (!erase) {
				if (num == 1) {
					if (str[s + 1] == str[e]) {
						s++;
						erase = true;
					}
				}
				else {
					if (str[s] == str[e - 1]) {
						e--;
						erase = true;
					}
				}
				if (!erase) {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		erase = false;
		string str;
		cin >> str;

		erase = false;

		if (check(str, 1)) {
			if (erase) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			cout << '\n';
			continue;
		}

		erase = false;

		if (check(str, 2)) {
			if (erase) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			cout << '\n';
			continue;
		}

		cout << 2;
		cout << '\n';
	}
}
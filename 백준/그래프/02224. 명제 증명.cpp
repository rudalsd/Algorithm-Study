#include<iostream>
#include<string>

using namespace std;

int N;
int arr[52][52];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a;
		cin >> b >> b;

		if (a[0] <= 'Z') {
			a[0] -= 'A';
		}
		else {
			a[0] -= 'a';
			a[0] += 26;
		}

		if (b[0] <= 'Z') {
			b[0] -= 'A';
		}
		else {
			b[0] -= 'a';
			b[0] += 26;
		}

		arr[a[0]][b[0]] = 1;
	}

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			for (int k = 0; k < 52; k++) {
				if (arr[j][i] == 1 && arr[i][k] == 1) {
					arr[j][k] = 1;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (arr[i][j] == 1 && i != j) {
				ans++;
			}
		}
	}

	cout << ans << '\n';

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (arr[i][j] == 1 && i != j) {
				if (i < 26) {
					if (j < 26) {
						cout << (char)(i + 'A') << " => " << (char)(j + 'A');
					}
					else {
						cout << (char)(i + 'A') << " => " << (char)(j + 'a' - 26);
					}
				}
				else {
					if (j < 26) {
						cout << (char)(i + 'a' - 26) << " => " << (char)(j + 'A');
					}
					else {
						cout << (char)(i + 'a' - 26) << " => " << (char)(j + 'a' - 26);
					}
				}
				cout << '\n';
			}
		}
	}
}
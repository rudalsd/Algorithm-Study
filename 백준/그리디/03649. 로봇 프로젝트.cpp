#include<iostream>
#include<algorithm>

using namespace std;

int x, n;
int arr[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> x) {
		x *= 10000000;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int l = 0;
		int r = n - 1;
		bool flag = false;

		while (l < r) {
			if (arr[l] + arr[r] == x) {
				cout << "yes " << arr[l] << ' ' << arr[r];
				flag = true;
				break;
			}
			else if (arr[l] + arr[r] < x) {
				l++;
			}
			else if (arr[l] + arr[r] > x) {
				r--;
			}
		}

		if (flag == false) {
			cout << "danger";
		}

		cout << '\n';
	}
}

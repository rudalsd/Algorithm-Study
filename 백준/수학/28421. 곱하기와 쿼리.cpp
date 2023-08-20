#include<iostream>

using namespace std;

int N, Q;
int arr[100001];
int box[20001];

bool check(int x)
{
	int i = 1;

	if (N == 1) return false;

	if (x == 0) {
		if (box[0]) {
			return true;
		}
		else return false;
	}

	if (x > 10000) {
		i = x / 10000;
	}

	for (i; i * i <= x; i++) {
		if (box[i] && x % i == 0 && box[x / i]) {
			if (i * i == x && box[i] < 2) {
				continue;
			}
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		box[arr[i]]++;
	}

	for (int i = 0; i < Q; i++) {
		int cmd, x;
		cin >> cmd >> x;

		if (cmd == 1) {

			if (check(x)) {
				cout << 1;
			}
			else {
				cout << 0;
			}

			cout << '\n';
		}
		else {
			box[0]++;
			box[arr[x]]--;
			arr[x] = 0;
		}
	}
}
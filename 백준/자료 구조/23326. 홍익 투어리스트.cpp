#include<iostream>
#include<set>

using namespace std;

int N, Q;
int cur = 1;
int arr[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	set<int> s;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			s.insert(i);
		}
	}

	for (int i = 0; i < Q; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int i;
			cin >> i;
			if (arr[i] == 0) {
				arr[i] = 1;
				s.insert(i);
			}
			else {
				arr[i] = 0;
				s.erase(i);
			}
		}
		else if (cmd == 2) {
			int x;
			cin >> x;
			if (x > N) {
				x %= N;
			}
			cur += x;
			if (cur > N) {
				cur -= N;
			}

		}
		else {
			if (s.empty()) {
				cout << -1 << '\n';;
			}
			else {
				if (s.lower_bound(cur) == s.end()) {
					cout << N - cur + (*s.lower_bound(0)) << '\n';;
				}
				else {
					cout << (*s.lower_bound(cur)) - cur << '\n';;
				}
			}
		}
	}
}

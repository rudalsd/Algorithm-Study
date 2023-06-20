#include<iostream>
#include<stack>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	stack<int> s;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		while (!s.empty() && s.top() >= y) {
			if (s.top() != y) cnt++;
			s.pop();
		}

		s.push(y);
	}

	while (!s.empty() && s.top() >= 0) {
		if (s.top() != 0) cnt++;
		s.pop();
	}

	cout << cnt;
}

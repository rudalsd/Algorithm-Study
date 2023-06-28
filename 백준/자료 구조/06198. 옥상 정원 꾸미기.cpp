#include<iostream>
#include<stack>
#define ll long long

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	stack<int> st;

	ll cnt = 0;

	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;

		if (i == 0) {
			st.push(h);
		}
		else {
			while (st.top() <= h) {
				st.pop();
				if (st.empty()) break;
			}

			cnt += st.size();
			st.push(h);
		}
	}

	cout << cnt;
}

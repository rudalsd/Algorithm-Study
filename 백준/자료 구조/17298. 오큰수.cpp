#include<iostream>
#include<stack>

using namespace std;

int N;
int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	fill(arr, arr + N + 1, -1);

	stack<pair<int, int>> st;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		if (!st.empty()) {
			while (st.top().first < n) {
				arr[st.top().second] = n;
				st.pop();
				if (st.empty()) break;
			}
		}

		st.push({ n,i });
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
}

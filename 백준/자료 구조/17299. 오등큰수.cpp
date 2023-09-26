#include<iostream>
#include<stack>

using namespace std;

int N;
int arr[1000000];
int cnt[1000001];
int NGF[1000000];
stack<pair<int, int>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	fill(NGF, NGF + N, -1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 0; i < N; i++) {
		if (!s.empty()) {
			while (s.top().first < cnt[arr[i]]) {
				NGF[s.top().second] = arr[i];
				s.pop();
				if (s.empty()) break;
			}
		}

		s.push({ cnt[arr[i]], i });
	}

	for (int i = 0; i < N; i++) {
		cout << NGF[i] << ' ';
	}
}

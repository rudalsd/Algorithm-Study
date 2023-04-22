#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, K, S;
vector<pair<int, int>> arr1;
vector<pair<int, int>> arr2;

int main()
{
	scanf("%d %d %d", &N, &K, &S);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a < S) {
			arr1.push_back({ a,b });
		}
		else {
			arr2.push_back({ a,b });
		}
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end(), greater<>());

	int ans = 0;

	int bus = 0;

	for (auto& next : arr1) {
		const int pos = next.first;
		int cnt = next.second;

		if (cnt >= K) {
			ans += (S - pos) * 2 * (int)(cnt / K);
			cnt %= K;
		}
		
		if (cnt > 0) {
			if (bus == 0) {
				ans += (S - pos) * 2;
				bus = cnt;
			}
			else {
				if (bus + cnt > K) {
					ans += (S - pos) * 2;
					bus = bus + cnt - K;
				}
				else {
					bus += cnt;
				}
			}
		}
	}

	bus = 0;

	for (auto& next : arr2) {
		const int pos = next.first;
		int cnt = next.second;

		if (cnt >= K) {
			ans += (pos - S) * 2 * (int)(cnt / K);
			cnt %= K;
		}

		if (cnt > 0) {
			if (bus == 0) {
				ans += (pos - S) * 2;
				bus = cnt;
			}
			else {
				if (bus + cnt > K) {
					ans += (pos - S) * 2;
					bus = bus + cnt - K;
				}
				else {
					bus += cnt;
				}
			}
		}
	}

	printf("%d", ans);
}
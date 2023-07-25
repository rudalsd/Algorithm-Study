#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int a[100001];
int b[100001];
vector<pair<int, int>> arr;

bool cmp(pair<int, int> left, pair<int, int> right) 
{
	if (left.first == right.first) return left.second > right.second;
	return left.first < right.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		a[n] = i;
	}

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		b[n] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = max(1, i - 4); j <= min(N, i + 4); j++) {
			arr.push_back({ a[i], b[j] });
		}
	}

	sort(arr.begin(), arr.end(), cmp);

	vector<int>lis;

	for (auto& next : arr) {
		if (lis.empty()) {
			lis.push_back(next.second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), next.second);
			if (it == lis.end()) {
				lis.push_back(next.second);
			}
			else {
				*it = next.second;
			}
		}
	}

	cout << lis.size();
}
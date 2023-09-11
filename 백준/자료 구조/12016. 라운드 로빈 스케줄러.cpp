#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int N;
int segTree[200000];
pair<int, int> arr[100001];
ll ans[100001];

bool cmp(pair<int, int> left, pair<int, int> right)
{
	if (left.first == right.first) return left.second > right.second;
	return left.first < right.first;
}

void updateTree(int idx, int diff)
{
	while (idx) {
		segTree[idx] += diff;
		idx >>= 1;
	}
}

int getTree(int l, int r)
{
	int ret = 0;

	while (l <= r) {
		if (l & 1) {
			ret += segTree[l];
			l++;
		}
		if (~r & 1) {
			ret += segTree[r];
			r--;
		}

		l >>= 1;
		r >>= 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		updateTree(N + i - 1, 1);
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr + 1, arr + N + 1, cmp);

	int temp = arr[1].first;
	int cnt = 0;
	int Cnt = N;
	int cur = arr[1].first - 1;
	ll Cur = 0;

	for (int i = 1; i <= N; i++) {
		if (temp == arr[i].first) {
			cnt++;
			ans[arr[i].second] = Cur + (ll)getTree(N, N + arr[i].second - 1) + 1LL * cur * Cnt;
			updateTree(N + arr[i].second - 1, -1);
		}
		else {
			Cur += 1LL * Cnt * (1LL * cur + 1);
			Cnt -= cnt;
			cnt = 0;
			cur = arr[i].first - arr[i - 1].first - 1;
			temp = arr[i].first;
			i--;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}
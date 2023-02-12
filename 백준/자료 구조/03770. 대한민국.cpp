#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int T;
pair<int, int> arr[400001];

void updateTree(int node, int s, int e, int idx, ll* segTree)
{
	if (idx < s || e < idx) return;
	segTree[node]++;

	if (s != e) {
		int m = (s + e) / 2;
		updateTree(node * 2, s, m, idx, segTree);
		updateTree(node * 2 + 1, m + 1, e, idx, segTree);
	}
}

ll sumTree(int node, int s, int e, int sidx, int eidx, ll* segTree)
{
	if (sidx > e || eidx < s) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	ll left = sumTree(node * 2, s, m, sidx, eidx, segTree);
	ll right = sumTree(node * 2 + 1, m + 1, e, sidx, eidx, segTree);

	return left + right;
}

int main()
{
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M, K;
		ll segTree[2050] = { 0 };
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
		}

		sort(arr, arr + K);

		ll ans = 0;

		for (int i = 0; i < K; i++) {
			updateTree(1, 1, M, arr[i].second, segTree);
			ans += sumTree(1, 1, M, arr[i].second + 1, M, segTree);
		}

		printf("Test case %d: %lld\n", t, ans);
	}
}
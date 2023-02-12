#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int N, M;
pair<int, int> arr[2000000];
ll segTree[5000];

void updateTree(int node, int s, int e, int idx)
{
	if (s > idx || e < idx) return;
	segTree[node] += 1;

	if (s != e) {
		int m = (s + e) / 2;
		updateTree(node * 2, s, m, idx);
		updateTree(node * 2 + 1, m + 1, e, idx);
	}
}

ll sumTree(int node, int s, int e, int sidx, int eidx)
{
	if (s > eidx || e < sidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	ll left = sumTree(node * 2, s, m, sidx, eidx);
	ll right = sumTree(node * 2 + 1, m + 1, e, sidx, eidx);

	return left + right;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr, arr + M);

	ll ans = 0;

	for (int i = 0; i < M; i++) {
		int cur = arr[i].second;
		
		updateTree(1, 1, N, cur);
		ans += sumTree(1, 1, N, cur + 1, N);
	}

	printf("%lld", ans);
}
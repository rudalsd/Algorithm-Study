#include<iostream>
#define ll long long

using namespace std;

int T;
ll segTree[263000];
int arr[100001];

void updateTree(int node, int s, int e, int idx)
{
	if (s > idx || e < idx) return;
	segTree[node]++;

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
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);
		fill_n(segTree, 263000, 0);
		
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			arr[num] = i;
		}

		ll ans = 0;

		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			updateTree(1, 1, n, arr[num]);
			ans += sumTree(1, 1, n, arr[num] + 1, n);
		}

		printf("%lld\n", ans);
	}
}
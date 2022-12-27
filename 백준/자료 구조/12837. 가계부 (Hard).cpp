#include<iostream>
#define ll long long

using namespace std;

int N, Q;
ll segTree[2100000];

ll sumTree(int node, int start, int end, int sidx, int eidx)
{
	if (end < sidx || start > eidx) return 0;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	ll left = sumTree(node * 2, start, mid, sidx, eidx);
	ll right = sumTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}

void modifyTree(int node, int start, int end, int idx, ll x)
{
	if (idx < start || idx > end) return;
	segTree[node] += x;

	if (start != end) {
		int mid = (start + end) / 2;
		modifyTree(node * 2, start, mid, idx, x);
		modifyTree(node * 2 + 1, mid + 1, end, idx, x);
	}
}

int main()
{
	scanf("%d %d", &N, &Q);

	for (int i = 0; i < Q; i++) {
		int n, p, q;
		scanf("%d %d %d", &n, &p, &q);

		if (n == 1) {
			modifyTree(1, 1, N, p, q);
		}
		else {
			printf("%lld\n", sumTree(1, 1, N, p, q));
		}
	}
}
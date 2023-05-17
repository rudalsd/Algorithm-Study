#include<iostream>

using namespace std;

int N;
int segTree[262222];
int lazy[262222];
int cnt[100001];

void updateLazy(int node, int s, int e)
{
	if (lazy[node] != 0) {
		segTree[node] += lazy[node];

		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void updateTree(int node, int s, int e, int sidx, int eidx)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		segTree[node]++;

		if (s != e) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx);
}

int getTree(int node, int s, int e, int idx)
{
	updateLazy(node, s, e);

	if (s > idx || e < idx) return 0;
	if (s == e) return segTree[node];

	int m = (s + e) / 2;
	int left = getTree(node * 2, s, m, idx);
	int right = getTree(node * 2 + 1, m + 1, e, idx);

	return  left + right;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int L, R;
		scanf("%d %d", &L, &R);

		if (L + 1 <= R - 1) {
			updateTree(1, 1, 100000, L + 1, R - 1);
		}

		int tempL = getTree(1, 1, 100000, L);
		int tempR = getTree(1, 1, 100000, R);

		printf("%d\n", tempL + tempR - cnt[L] - cnt[R]);

		cnt[L] = tempL;
		cnt[R] = tempR;
	}
}
#include<iostream>

using namespace std;

int segTree[262222];
int lazy[262222];
int N, M;

void modifyLazy(int node, int s, int e)
{
	if (lazy[node] == 1) {
		segTree[node] = e - s + 1 - segTree[node];
		if (s != e) {
			lazy[node * 2] *= -1;
			lazy[node * 2 + 1] *= -1;
		}
		lazy[node] *= -1;
	}
}

void modifyTree(int node, int s, int e, int sidx, int eidx)
{
	modifyLazy(node, s, e);

	if (eidx < s || e < sidx) return;

	if (sidx <= s && e <= eidx) {
		segTree[node] = e - s + 1 - segTree[node];
		if (s != e) {
			lazy[node * 2] *= -1;
			lazy[node * 2 + 1] *= -1;
		}
		return;
	}

	int m = (s + e) / 2;
	modifyTree(node * 2, s, m, sidx, eidx);
	modifyTree(node * 2 + 1, m + 1, e, sidx, eidx);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int getTree(int node, int s, int e, int sidx, int eidx)
{
	modifyLazy(node, s, e);

	if (eidx < s || e < sidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	return getTree(node * 2, s, m, sidx, eidx) + getTree(node * 2 + 1, m + 1, e, sidx, eidx);
}

int main()
{
	fill(lazy, lazy + 262222, -1);

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int O, S, T;

		scanf("%d %d %d", &O, &S, &T);

		if (S > T) swap(S, T);

		if (O == 0) {
			modifyTree(1, 1, N, S, T);
		}
		else {
			printf("%d\n", getTree(1, 1, N, S, T));
		}
	}
}
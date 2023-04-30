#include<iostream>

using namespace std;

int N, M;
int arr[500001];
int segTree[1050000];
int lazy[1050000];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = segTree[node * 2] ^ segTree[node * 2 + 1];
}

void updateLazy(int node, int s, int e)
{
	if (lazy[node] != 0) {
		if ((e - s + 1) % 2 == 1) {
			segTree[node] ^= lazy[node];
		}

		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}

		lazy[node] = 0;
	}
}

void updateTree(int node, int s, int e, int sidx, int eidx, int k)
{
	updateLazy(node, s, e);

	if (e < sidx || s > eidx) return;
	if (sidx <= s && e <= eidx) {
		lazy[node] ^= k;
		updateLazy(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, k);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, k);

	segTree[node] = segTree[node * 2] ^ segTree[node * 2 + 1];
}

int getTree(int node, int s, int e, int sidx, int eidx)
{
	updateLazy(node, s, e);

	if (e < sidx || s > eidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	return getTree(node * 2, s, m, sidx, eidx) ^ getTree(node * 2 + 1, m + 1, e, sidx, eidx);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 0, N - 1);

	scanf("%d", &M);

	for (int q = 0; q < M; q++) {
		int n, i, j, k;
		scanf("%d %d %d", &n, &i, &j);

		if (n == 1) {
			scanf("%d", &k);
			updateTree(1, 0, N - 1, i, j, k);
		}
		else {
			printf("%d\n", getTree(1, 0, N - 1, i, j));
		}
	}
}
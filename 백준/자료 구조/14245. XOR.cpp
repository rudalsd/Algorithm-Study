#include<iostream>

using namespace std;

int n, m;
int segTree[1050000];
int lazy[1050000];
int arr[500000];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr[s];
		return;
	}

	int m = (s + e)/2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);
}

void updateLazy(int node, int s, int e)
{
	if (lazy[node] != 0) {
		segTree[node] ^= lazy[node];

		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}

		lazy[node] = 0;
	}
}

void updateTree(int node, int s, int e, int sidx, int eidx, int a)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		segTree[node] ^= a;
		if (s != e) {
			lazy[node * 2] ^= a;
			lazy[node * 2 + 1] ^= a;
		}
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, a);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, a);
}

void getTree(int node, int s, int e, int idx)
{
	updateLazy(node, s, e);

	if (idx < s || e < idx) return;
	if (s == e) {
		printf("%d\n", segTree[node]);
		return;
	}

	int m = (s + e) / 2;
	getTree(node * 2, s, m, idx);
	getTree(node * 2 + 1, m + 1, e, idx);
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 0, n - 1);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 1) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			updateTree(1, 0, n - 1, a, b, c);
		}
		else {
			int a;
			scanf("%d", &a);

			getTree(1, 0, n - 1, a);
		}
	}
}
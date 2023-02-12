#include<iostream>
#define ll long long

using namespace std;

int N, M;
ll arr[100001];
ll segTree[263000];
ll lazy[263000];

void makeTree(int node, int start, int end)
{
	if (start == end) {
		segTree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	makeTree(node * 2, start, mid);
	makeTree(node * 2 + 1, mid + 1, end);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void modifyLazy(int node, int start, int end)
{
	if (lazy[node] != 0) {
		segTree[node] += (ll)(end - start + 1) * lazy[node];

		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void modifyTree(int node, int start, int end, int i, int j, ll k)
{
	modifyLazy(node, start, end);

	if (start > j || end < i) return;

	if (i <= start && end <= j) {
		lazy[node] += k;
		modifyLazy(node, start, end);

		return;
	}

	int mid = (start + end) / 2;
	modifyTree(node * 2, start, mid, i, j, k);
	modifyTree(node * 2 + 1, mid + 1, end, i, j, k);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void getTree(int node, int start, int end, int x)
{
	modifyLazy(node, start, end);

	if (start > x || x > end) return;
	if (start == end) {
		arr[start] = segTree[node];
		return;
	}

	int mid = (start + end) / 2;
	getTree(node * 2, start, mid, x);
	getTree(node * 2 + 1, mid + 1, end, x);
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	makeTree(1, 1, N);

	scanf("%d", &M);

	for (int m = 0; m < M; m++) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 1) {
			int i, j;
			ll k;
			scanf("%d %d %lld", &i, &j, &k);
			modifyTree(1, 1, N, i, j, k);
		}
		else {
			int x;
			scanf("%d", &x);
			getTree(1, 1, N, x);

			printf("%lld\n", arr[x]);
		}
	}
}
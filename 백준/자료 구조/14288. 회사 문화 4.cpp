#include<iostream>
#include<vector>

using namespace std;

int n, m;
int s[100001];
int e[100001];
int cnt;
int segTree[262222];
int lazy[262222];
int segTree2[200000];
vector<int> list[100001];
int cur = -1;
int ans;

void dfs(int num)
{
	s[num] = ++cnt;

	for (int& next : list[num]) {
		dfs(next);
	}

	e[num] = cnt;
}

void updateLazy(int node, int l, int r)
{
	if (lazy[node] != 0) {
		segTree[node] += lazy[node];

		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void updateTree(int node, int l, int r, int lidx, int ridx, int diff)
{
	updateLazy(node, l, r);

	if (r < lidx || ridx < l) return;
	if (lidx <= l && r <= ridx) {
		if (l == r) {
			segTree[node] += diff;
		}
		else {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}

		return;
	}

	int m = (l + r) / 2;
	updateTree(node * 2, l, m, lidx, ridx, diff);
	updateTree(node * 2 + 1, m + 1, r, lidx, ridx, diff);
}

void updateTree2(int node, int diff)
{
	while (node != 0) {
		segTree2[node] += diff;
		node >>= 1;
	}
}

void getTree(int node, int l, int r, int idx)
{
	updateLazy(node, l, r);

	if (idx < l || r < idx) return;

	if (l == r) {
		ans += segTree[node];
		return;
	}

	int m = (l + r) / 2;
	getTree(node * 2, l, m, idx);
	getTree(node * 2 + 1, m + 1, r, idx);
}

void getTree2(int l, int r)
{
	while (l <= r) {
		if (l & 1) {
			ans += segTree2[l];
			l++;
		}
		if (~r & 1) {
			ans += segTree2[r];
			r--;
		}

		l >>= 1;
		r >>= 1;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int p;
		scanf("%d", &p);

		if (p != -1) {
			list[p].push_back(i);
		}
	}

	dfs(1);

	for (int j = 0; j < m; j++) {
		int com;
		scanf("%d", &com);
		if (com == 1) {
			int i, w;
			scanf("%d %d", &i, &w);

			if (cur == -1) {
				updateTree(1, 1, n, s[i], e[i], w);
			}
			else {
				updateTree2(n + s[i] - 1, w);
			}
		}
		else if (com == 2) {
			int i;
			scanf("%d", &i);

			ans = 0;

			getTree(1, 1, n, s[i]);
			getTree2(n + s[i] - 1, n + e[i] - 1);

			printf("%d\n", ans);
		}
		else {
			cur *= -1;
		}
	}
}
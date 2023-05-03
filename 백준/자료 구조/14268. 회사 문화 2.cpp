#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> list[100001];
int cnt;
int s[100001];
int e[100001];
int segTree[262222];
int lazy[262222];

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

	return;
}

void updateTree(int node, int s, int e, int sidx, int eidx, int diff)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		segTree[node] += diff;
		if (s != e) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, diff);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, diff);
}

void query(int node, int s, int e, int idx)
{
	updateLazy(node, s, e);

	if (idx < s || idx > e) return;

	if (s == e) {
		printf("%d\n", segTree[node]);
		return;
	}

	int m = (s + e) / 2;
	query(node * 2, s, m, idx);
	query(node * 2 + 1, m + 1, e, idx);
}

void dfs(int num)
{
	s[num] = ++cnt;

	for (int next : list[num]) {
		dfs(next);
	}

	e[num] = cnt;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int parent;
		scanf("%d", &parent);

		if (parent != -1) {
			list[parent].push_back(i);
		}
	}

	dfs(1);

	for (int j = 0; j < m; j++) {
		int com, i;
		scanf("%d %d", &com, &i);

		if (com == 1) {
			int w;
			scanf("%d", &w);

			updateTree(1, 1, n, s[i], e[i], w);
		}
		else {
			query(1, 1, n, s[i]);
		}
	}
}
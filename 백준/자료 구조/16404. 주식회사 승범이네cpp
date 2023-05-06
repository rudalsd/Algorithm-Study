#include<iostream>
#include<vector>

using namespace std;

int N, M;
int st[100001];
int en[100001];
int segTree[262222];
int lazy[262222];
vector<int> list[100001];
int cnt;

void dfs(int num)
{
	st[num] = ++cnt;

	for (int& next : list[num]) {
		dfs(next);
	}

	en[num] = cnt;
}

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

void updateTree(int node, int s, int e, int sidx, int eidx, int diff)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		if (s == e) {
			segTree[node] += diff;
		}
		else {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, diff);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, diff);
}

void getTree(int node, int s, int e, int idx)
{
	updateLazy(node, s, e);

	if (e < idx || s > idx) return;
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
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int p;
		scanf("%d", &p);

		if (p != -1) {
			list[p].push_back(i);
		}
	}

	dfs(1);

	for (int j = 0; j < M; j++) {
		int com, i;
		scanf("%d %d", &com, &i);

		if (com == 1) {
			int w;
			scanf("%d", &w);

			updateTree(1, 1, N, st[i], en[i], w);
		}
		else {
			getTree(1, 1, N, st[i]);
		}
	}
}
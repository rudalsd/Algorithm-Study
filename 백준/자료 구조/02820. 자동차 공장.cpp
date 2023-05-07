#include<iostream>
#include<vector>

using namespace std;

int N, M;
unsigned int segTree[1050000];
unsigned int lazy[1050000];
vector<int> list[500001];
int st[500001];
int en[500001];
int arr[500001];
int arr2[500001];
int cnt;

void dfs(int num)
{
	st[num] = ++cnt;
	arr2[cnt] = arr[num];

	for (int& next : list[num]) {
		dfs(next);
	}

	en[num] = cnt;
}

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr2[s];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);
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

void updateTree(int node, int s, int e, int sidx, int eidx, unsigned int diff)
{
	updateLazy(node, s, e);

	if (e < sidx || s > eidx) return;
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

	if (idx < s || idx > e) return;
	if (s == e) {
		cout << segTree[node] << '\n';
		return;
	}

	int m = (s + e) / 2;
	getTree(node * 2, s, m, idx);
	getTree(node * 2 + 1, m + 1, e, idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i != 1) {
			int p;
			cin >> p;
			list[p].push_back(i);
		}
	}

	dfs(1);

	makeTree(1, 1, N);

	for (int i = 0; i < M; i++) {
		char com;
		int a;
		cin >> com >> a;

		if (com == 'p') {
			unsigned int x;
			cin >> x;

			updateTree(1, 1, N, st[a] + 1, en[a], x);
		}
		else {
			getTree(1, 1, N, st[a]);
		}
	}
}
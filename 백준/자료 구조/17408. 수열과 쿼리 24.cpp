#include<iostream>

using namespace std;

int N, M;
pair<int,int> segTree[262222];
int arr[100001];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = { arr[s], s};
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	if (segTree[node*2].first > segTree[node*2+1].first) {
		segTree[node] = segTree[node * 2];
	}
	else {
		segTree[node] = segTree[node * 2 + 1];
	}
}

void updateTree(int node, int s, int e, int idx, int v)
{
	if (idx < s || e < idx) return;
	if (s == e) {
		segTree[node].first = v;
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, idx, v);
	updateTree(node * 2 + 1, m + 1, e, idx, v);

	if (segTree[node * 2].first > segTree[node * 2 + 1].first) {
		segTree[node] = segTree[node * 2];
	}
	else {
		segTree[node] = segTree[node * 2 + 1];
	}
}

pair<int,int> getTree(int node, int s, int e, int sidx, int eidx)
{
	if (e < sidx || s > eidx) return { 0,0 };
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	pair<int, int> left = getTree(node * 2, s, m, sidx, eidx);
	pair<int, int> right = getTree(node * 2 + 1, m + 1, e, sidx, eidx);

	if (left.first > right.first) {
		return left;
	}
	else {
		return right;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	makeTree(1, 1, N);

	cin >> M;

	for (int t = 0; t < M; t++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int i, v;
			cin >> i >> v;
			updateTree(1, 1, N, i, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			int idx = getTree(1, 1, N, l, r).second;

			int ans = max(getTree(1, 1, N, l, idx).first + getTree(1, 1, N, idx + 1, r).first, getTree(1, 1, N, l, idx - 1).first + getTree(1, 1, N, idx, r).first);
			cout << ans << '\n';
		}
	}
}
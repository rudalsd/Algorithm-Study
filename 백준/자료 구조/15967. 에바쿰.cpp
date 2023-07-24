#include<iostream>
#define ll long long

using namespace std;

ll segTree[2100000];
int lazy[2100000];
int N, Q1, Q2;
int arr[1000001];

void updateLazy(int node, int s, int e)
{
	if (lazy[node]) {
		segTree[node] += 1LL * lazy[node] * (1LL * e - s + 1);
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateTree(int node, int s, int e, int sidx, int eidx, int diff)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		segTree[node] += 1LL * diff * (1LL * e - s + 1);
		if (s != e) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	
	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, diff);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, diff);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

ll getTree(int node, int s, int e, int sidx, int eidx)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	ll left = getTree(node * 2, s, m, sidx, eidx);
	ll right = getTree(node * 2 + 1, m + 1, e, sidx, eidx);

	return left + right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q1 >> Q2;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	makeTree(1, 1, N);

	for (int i = 0; i < Q1 + Q2; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int n, m;
			cin >> n >> m;
			cout << getTree(1, 1, N, n, m) << '\n';
		}
		else {
			int s, e, l;
			cin >> s >> e >> l;
			updateTree(1, 1, N, s, e, l);
		}
	}
}
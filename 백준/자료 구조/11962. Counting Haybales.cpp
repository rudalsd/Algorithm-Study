#include<iostream>
#define ll long long

using namespace std;

struct node {
	ll sum;
	ll min;
};

int N, Q;
int arr[200001];
node segTree[524300];
ll lazy[524300];

void updateLazy(int node, int s, int e)
{
	if (lazy[node]) {
		segTree[node].sum += lazy[node] * (1LL * e - s + 1);
		segTree[node].min += lazy[node];

		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}

	return;
}

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node].sum = 1LL * arr[s];
		segTree[node].min = 1LL * arr[s];

		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node].sum = segTree[node * 2].sum + segTree[node * 2 + 1].sum;
	segTree[node].min = min(segTree[node * 2].min, segTree[node * 2 + 1].min);

	return;
}

void updateTree(int node, int s, int e, int sidx, int eidx, int C)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return;
	if (sidx <= s && e <= eidx) {
		segTree[node].sum += (1LL * e - s + 1) * (1LL * C);
		segTree[node].min += C;

		if (s != e) {
			lazy[node * 2] += C;
			lazy[node * 2 + 1] += C;
		}

		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, sidx, eidx, C);
	updateTree(node * 2 + 1, m + 1, e, sidx, eidx, C);

	segTree[node].sum = segTree[node * 2].sum + segTree[node * 2 + 1].sum;
	segTree[node].min = min(segTree[node * 2].min, segTree[node * 2 + 1].min);

	return;
}

ll getSum(int node, int s, int e, int sidx, int eidx)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node].sum;

	int m = (s + e) / 2;
	
	return getSum(node * 2, s, m, sidx, eidx) + getSum(node * 2 + 1, m + 1, e, sidx, eidx);
}

ll getMin(int node, int s, int e, int sidx, int eidx)
{
	updateLazy(node, s, e);

	if (s > eidx || e < sidx) return 11111111111;
	if (sidx <= s && e <= eidx) return segTree[node].min;

	int m = (s + e) / 2;

	return min(getMin(node * 2, s, m, sidx, eidx), getMin(node * 2 + 1, m + 1, e, sidx, eidx));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	makeTree(1, 1, N);

	for (int i = 0; i < Q; i++) {
		char cmd;
		int A, B;
		cin >> cmd >> A >> B;

		if (cmd == 'M') {
			cout << getMin(1, 1, N, A, B) << '\n';
		}
		else if (cmd == 'P') {
			int C;
			cin >> C;


			updateTree(1, 1, N, A, B, C);
		}
		else {
			cout << getSum(1, 1, N, A, B) << '\n';
		}
	}
}

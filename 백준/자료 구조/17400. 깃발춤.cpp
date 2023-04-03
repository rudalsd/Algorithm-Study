#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int N, Q;
int arr[300001];
pair<ll, ll> segTree[1050000];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		if (s % 2 == 0) {
			segTree[node].first = arr[s];
		}
		else {
			segTree[node].second = arr[s];
		}
		return;
	}

	int m = (s + e) / 2;

	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node].first = segTree[node * 2].first + segTree[node * 2 + 1].first;
	segTree[node].second = segTree[node * 2].second + segTree[node * 2 + 1].second;
}

pair<ll,ll> getTree(int node, int s, int e, int sidx, int eidx)
{
	if (eidx < s || e < sidx) return { 0,0 };
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;

	pair<ll, ll> left = getTree(node * 2, s, m, sidx, eidx);
	pair<ll, ll> right = getTree(node * 2 + 1, m+1, e, sidx, eidx);
	
	return { left.first + right.first, left.second + right.second };
}

void updateTree(int node, int s, int e, int idx, int x)
{
	if (s > idx || e < idx) return;
	if (idx % 2 == 0) {
		segTree[node].first += x;
	}
	else {
		segTree[node].second += x;
	}

	if (s != e) {
		int m = (s + e) / 2;

		updateTree(node * 2, s, m, idx, x);
		updateTree(node * 2 + 1, m + 1, e, idx, x);
	}
}

int main()
{
	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = 0; i < Q; i++) {
		int com, L, R;
		scanf("%d %d %d", &com, &L, &R);

		if (com == 1) {
			pair<ll, ll> temp = getTree(1, 1, N, L, R);
			printf("%lld\n", abs(temp.first - temp.second));
		}
		else {
			updateTree(1, 1, N, L, R);
		}
	}
}
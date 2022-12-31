#include<iostream>
#define ll long long

using namespace std;

int N, Q;
ll arr[100001];
ll segTree[263000];

ll makeTree(ll node, ll start, ll end)
{
	if (start == end) return segTree[node] = arr[start];

	int mid = (start + end) / 2;
	ll left = makeTree(node * 2, start, mid);
	ll right = makeTree(node * 2 + 1, mid + 1, end);

	return segTree[node] = right + left;
}

void modifyTree(ll node, ll start, ll end, ll a, ll diff)
{
	if (a < start || a > end) return;
	segTree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		modifyTree(node * 2, start, mid, a, diff);
		modifyTree(node * 2 + 1, mid + 1, end, a, diff);
	}
}

ll sumTree(ll node, ll start, ll end, ll x, ll y)
{
	if (y < start || x > end) return 0;
	if (x <= start && end <= y) return segTree[node];

	int mid = (start + end) / 2;
	ll left = sumTree(node * 2, start, mid, x, y);
	ll right = sumTree(node * 2 + 1, mid + 1, end, x, y);

	return left + right;
}

int main()
{
	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	makeTree(1,1,N);

	for (int i = 0; i < Q; i++) {
		ll x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (y < x) {
			ll temp = x;
			x = y;
			y = temp;
		}
		ll diff = b - arr[a];
		arr[a] = b;
		printf("%lld\n", sumTree(1, 1, N, x, y));
		modifyTree(1, 1, N, a, diff);
	}
}
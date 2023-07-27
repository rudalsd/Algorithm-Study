#include<iostream>
#define ll long long

using namespace std;

int n;
int segTree[200000];
int arr[100000];
ll gop[100000];
ll ans;

void updateTree(int idx)
{
	while (idx) {
		segTree[idx]++;
		idx >>= 1;
	}
}

int getTree(int l, int r)
{
	int ret = 0;

	while (l <= r) {
		if (l & 1) {
			ret += segTree[l];
			l++;
		}
		if (~r & 1) {
			ret += segTree[r];
			r--;
		}
		l >>= 1;
		r >>= 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		gop[i] = getTree(n + arr[i], 2 * n - 1);
		updateTree(n + arr[i] - 1);
	}

	fill(segTree, segTree + 2 * n, 0);

	for (int i = n - 1; i >= 0; i--) {
		gop[i] *= getTree(n, n + arr[i] - 2);
		updateTree(n + arr[i] - 1);
		ans += gop[i];
	}
	
	cout << ans;
}
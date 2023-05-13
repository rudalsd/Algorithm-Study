#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> list;
int arr[500001];
int segTree[1000000];

void updateTree(int idx)
{
	while (idx != 0) {
		segTree[idx] += 1;
		idx >>= 1;
	}
}

int query(int l, int r)
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
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);

		list.push_back(a);
		arr[i] = a;
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < N; i++) {
		int cur = lower_bound(list.begin(), list.end(), arr[i]) - list.begin();

		updateTree(cur + N);

		printf("%d\n", query(N + cur, 2 * N - 1));
	}
}
#include<iostream>

using namespace std;

int N;
int arr[100001];
int segTree[200000];

void updateTree(int idx, int k)
{
	while (idx != 0) {
		segTree[idx] += k;
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
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		updateTree(N + i, 1);

		arr[n] = i;
	}

	int L = 1;
	int R = N;
	int cnt = 1;

	while (L <= R) {
		if (cnt & 1) {
			printf("%d\n", getTree(N, N + arr[L]) - 1);
			updateTree(N + arr[L], -1);
			L++;
		}
		else {
			printf("%d\n", getTree(N + arr[R], 2 * N - 1) - 1);
			updateTree(N + arr[R], -1);
			R--;
		}
		cnt++;
	}
}
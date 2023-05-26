#include<iostream>

using namespace std;

int N;
int arr[100000];
int segTree[200002];
int pivot;

void updateTree(int idx)
{
	while (idx != 0) {
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
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = N - 1; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			pivot = i;
			break;
		}
	}

	for (int i = pivot; i < N; i++) {
		updateTree(N + arr[i] - 1);
	}

	printf("%d\n", pivot);
	for (int i = 0; i < pivot; i++) {
		printf("%d ", pivot - i - 1 + getTree(N, N + arr[i] - 1));
		updateTree(N + arr[i] - 1);
	}
}

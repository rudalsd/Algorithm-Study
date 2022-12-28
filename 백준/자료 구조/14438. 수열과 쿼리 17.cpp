#include<iostream>

using namespace std;

int segTree[263000];
int arr[100001];
int N, M;

int makeTree(int node, int start, int end)
{
	if (start == end) return segTree[node] = arr[start];

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);
	int right = makeTree(node * 2 + 1, mid + 1, end);

	if (right < left) {
		segTree[node] = right;
		return right;
	}
	else {
		segTree[node] = left;
		return left;
	}
}

int getTree(int node, int start, int end, int sidx, int eidx)
{
	if (start > eidx || end < sidx) return 1987654321;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	int left = getTree(node * 2, start, mid, sidx, eidx);
	int right = getTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	if (left < right) {
		return left;
	}
	else {
		return right;
	}
}

int modifyTree(int node, int start, int end, int idx, int v)
{
	if (idx > end || idx < start) return segTree[node];
	if (start == end) return segTree[node] = arr[start];

	int mid = (start + end) / 2;
	int left = modifyTree(node * 2, start, mid, idx, v);
	int right = modifyTree(node * 2 + 1, mid + 1, end, idx, v);

	if (left < right) {
		segTree[node] = left;
		return left;
	}
	else {
		segTree[node] = right;
		return right;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	scanf("%d", &M);

	for (int m = 0; m < M; m++) {
		int n;
		scanf("%d", &n);

		if (n == 1) {
			int i, v;
			scanf("%d %d", &i, &v);
			arr[i] = v;
			modifyTree(1, 1, N, i, v);
		}
		else {
			int i, j;
			scanf("%d %d", &i, &j);
			printf("%d\n", getTree(1, 1, N, i, j));
		}
	}
}
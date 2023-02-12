#include<iostream>

using namespace std;

int N, M;
int arr[100001];
int segTree[263000];

int makeTree(int node, int start, int end)
{
	if (start == end) return segTree[node] = arr[start];

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);
	int right = makeTree(node * 2 + 1, mid + 1, end);

	if (left < right) {
		return segTree[node] = left;
	}
	else {
		return segTree[node] = right;
	}
}

int getTree(int node, int start, int end, int sidx, int eidx)
{
	if (end < sidx || start > eidx) return 1987654321;
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

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", getTree(1, 1, N, a, b));
	}
}
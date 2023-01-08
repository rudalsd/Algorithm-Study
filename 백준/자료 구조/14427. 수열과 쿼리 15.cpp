#include<iostream>

using namespace std;

int N, M;
int arr[100001];
pair<int, int> segTree[263000];

pair<int, int> makeTree(int node, int start, int end)
{
	if (start == end)return segTree[node] = { arr[start], start };

	int mid = (start + end) / 2;
	pair<int, int> left = makeTree(node * 2, start, mid);
	pair<int, int> right = makeTree(node * 2 + 1, mid + 1, end);

	if (left <= right) {
		return segTree[node] = left;
	}
	else {
		return segTree[node] = right;
	}
}

pair<int, int> modifyTree(int node, int start, int end, int i, int v)
{
	if (i < start || end < i) return segTree[node];
	if (start == end) return segTree[node] = { arr[start], start };

	int mid = (start + end) / 2;
	pair<int, int> left = modifyTree(node * 2, start, mid, i, v);
	pair<int, int> right = modifyTree(node * 2 + 1, mid + 1, end, i, v);

	if (left <= right) {
		return segTree[node] = left;
	}
	else {
		return segTree[node] = right;
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
			printf("%d\n", segTree[1].second);
		}
	}
}
#include<iostream>

using namespace std;

int N;
int arr[100001];
int ans[100001];
int segTree[263000];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = 1;
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateTree(int node, int s, int e, int x, int i)
{
	segTree[node] -= 1;

	if (s == e) {
		ans[s] = i;
		return;
	}

	int m = (s + e) / 2;
	if (segTree[node * 2 + 1] < x) {
		updateTree(node * 2, s, m, x - segTree[node * 2 + 1], i);
	}
	else {
		updateTree(node * 2 + 1, m + 1, e, x, i);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = N; i > 0 ; i--) {
		updateTree(1, 1, N, arr[i] + 1, i);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", ans[i]);
	}
}
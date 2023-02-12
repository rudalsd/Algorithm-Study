#include<iostream>

using namespace std;

int N;
int arr[100001];
int segTree[263000];
int ans[100001];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = 1;
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m+1, e);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void getTree(int node, int s, int e, int x, int i)
{
	if (s == e) {
		segTree[node] = 0;
		ans[s] = i;
		return;
	}

	segTree[node] -= 1;

	int m = (s + e) / 2;
	if (segTree[node * 2] < x) {
		getTree(node * 2 + 1, m + 1, e, x - segTree[node * 2], i);
	}
	else {
		getTree(node * 2, s, m, x, i);
	}
}

int main()
{
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = 1; i <= N; i++) {
		getTree(1, 1, N, arr[i] + 1, i);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", ans[i]);
	}
}
#include<iostream>
#include<cmath>

using namespace std;

int N, M;
int segTree[1111111];
int arr[500001];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateTree(int node, int s, int e, int idx, int a)
{
	if (idx < s || e < idx) return;
	segTree[node] += a;

	if (s != e) {
		int m = (s + e) / 2;
		updateTree(node * 2, s, m, idx, a);
		updateTree(node * 2 + 1, m + 1, e, idx, a);
	}
}

void getTree(int node, int s, int e, int idx)
{
	if (s == e) {
		printf("%d\n", s);
		return;
	}

	int m = (s + e) / 2;
	int left = segTree[node * 2];
	
	if (left >= idx) {
		getTree(node * 2, s, m, idx);
	}
	else {
		getTree(node * 2 + 1, m + 1, e, idx - left);
	}

	return;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int com, idx;
		scanf("%d %d", &com, &idx);
		if (com == 1) {
			int a;
			scanf("%d", &a);
			arr[idx] += a;
			updateTree(1, 1, N, idx, a);
		}
		else {
			getTree(1, 1, N, idx);
		}
	}
}
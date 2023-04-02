#include<iostream>
#include<cmath>

using namespace std;

int N, M;
int segTree[2111111];
int arr[1000001];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = max(segTree[node * 2], segTree[node * 2 + 1]);
}

int getTree(int node, int s, int e, int sidx, int eidx)
{
	if (eidx < s || e < sidx) return 0;
	if (sidx <= s && e <= eidx) return segTree[node];

	int m = (s + e) / 2;
	int left = getTree(node * 2, s, m, sidx, eidx);
	int right = getTree(node * 2 + 1, m + 1, e, sidx, eidx);

	return max(left, right);
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = M; i <= N - M + 1; i++) {
		printf("%d\n", getTree(1, 1, N, i - (M - 1), i + M - 1));
	}
}
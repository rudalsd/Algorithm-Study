#include<iostream>

using namespace std;

int N, M;
int segTree[2050][2050];
int arr[1025][1025];

void updateTreeY(int node, int s, int e, int x, int y, int diff)
{
	if (y < s || e < y) return;
	segTree[x][node] += diff;

	if (s != e) {
		int m = (s + e) / 2;
		updateTreeY(node * 2, s, m, x, y, diff);
		updateTreeY(node * 2+1, m+1, e, x, y, diff);
	}
}

void updateTreeX(int node, int s, int e, int x, int y, int diff)
{
	if (x < s || e < x) return;
	updateTreeY(1, 1, N, node, y, diff);

	if (s != e) {
		int m = (s + e) / 2;
		updateTreeX(node * 2, s, m, x, y, diff);
		updateTreeX(node * 2 + 1, m + 1, e, x, y, diff);
	}
}

int sumTreeY(int node, int s, int e, int x, int y1, int y2)
{
	if (y2 < s || e < y1) return 0;
	if (y1 <= s && e <= y2) return segTree[x][node];

	int m = (s + e) / 2;
	int left = sumTreeY(node * 2, s, m, x, y1, y2);
	int right = sumTreeY(node * 2 + 1, m + 1, e, x, y1, y2);

	return left + right;
}

int sumTreeX(int node, int s, int e, int x1, int y1, int x2, int y2)
{
	if (x2 < s || e < x1) return 0;
	if (x1 <= s && e <= x2) return sumTreeY(1, 1, N, node, y1, y2);

	int m = (s + e) / 2;
	int left = sumTreeX(node * 2, s, m, x1, y1, x2, y2);
	int right = sumTreeX(node * 2 + 1, m + 1, e, x1, y1, x2, y2);

	return left + right;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			updateTreeX(1, 1, N, i, j, arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int w;
		scanf("%d", &w);

		if (w == 0) {
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			int diff = c - arr[x][y];
			arr[x][y] = c;
			updateTreeX(1, 1, N, x, y, diff);
		}
		else {
			int ans = 0;
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", sumTreeX(1, 1, N, x1, y1, x2, y2));
		}
	}
}
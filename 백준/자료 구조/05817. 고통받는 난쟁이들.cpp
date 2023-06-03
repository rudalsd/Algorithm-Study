#include<iostream>

using namespace std;

int N, M;
pair<int,int> segTree[524444];
int arr[200000];
int Min, Max;

void updateTree(int node, int s, int e, int idx, int n)
{
	if (idx < s || e < idx) return;
	if (s == e) {
		segTree[node] = { n, n };
		return;
	}

	int m = (s + e) / 2;
	updateTree(node * 2, s, m, idx, n);
	updateTree(node * 2 + 1, m + 1, e, idx, n);

	segTree[node].first = max(segTree[node * 2].first, segTree[node * 2 + 1].first);
	segTree[node].second = min(segTree[node * 2].second, segTree[node * 2 + 1].second);
}

void getTree(int node, int s, int e, int sidx, int eidx)
{
	if (e < sidx || s > eidx) return;
	if (sidx <= s && e <= eidx) {
		Min = min(Min, segTree[node].second);
		Max = max(Max, segTree[node].first);
		return;
	}

	int m = (s + e) / 2;
	getTree(node * 2, s, m, sidx, eidx);
	getTree(node * 2 + 1, m + 1, e, sidx, eidx);
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		updateTree(1, 1, N, arr[i], i);
	}

	for (int i = 0; i < M; i++) {
		int cmd, X, Y;
		scanf("%d %d %d", &cmd, &X, &Y);

		if (cmd == 1) {
			updateTree(1, 1, N, arr[Y], X);
			updateTree(1, 1, N, arr[X], Y);
			swap(arr[X], arr[Y]);
		}
		else {
			Min = 987654321;
			Max = 0;
			getTree(1, 1, N, X, Y);

			if (Y - X == Max - Min) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}
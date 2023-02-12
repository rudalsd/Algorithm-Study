#include<iostream>

using namespace std;

int N, M;
pair<int, int> segTree[263000];
int arr[100001];

pair<int, int> makeTree(int node, int start, int end)
{
	if (start == end) {
		if (arr[start] % 2 == 0) {
			return segTree[node] = { 0,1 };
		}
		else {
			return segTree[node] = { 1,0 };
		}
	}

	int mid = (start + end) / 2;
	pair<int, int> left = makeTree(node * 2, start, mid);
	pair<int, int> right = makeTree(node * 2 + 1, mid + 1, end);

	return segTree[node] = { left.first + right.first, left.second + right.second };
}

void modifyTree(int node, int start, int end, int idx, int odd, int even)
{
	if (idx < start || end < idx) return;

	segTree[node].first += odd;
	segTree[node].second += even;

	if (start != end) {
		int mid = (start + end) / 2;
		modifyTree(node * 2, start, mid, idx, odd, even);
		modifyTree(node * 2 + 1, mid + 1, end, idx, odd, even);
	}
}

int oddTree(int node, int start, int end, int sidx, int eidx)
{
	if (eidx < start || sidx > end) return 0;
	if (sidx <= start && end <= eidx) return segTree[node].first;

	int mid = (start + end) / 2;
	int left = oddTree(node * 2, start, mid, sidx, eidx);
	int right = oddTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}

int evenTree(int node, int start, int end, int sidx, int eidx)
{
	if (eidx < start || sidx > end) return 0;
	if (sidx <= start && end <= eidx) return segTree[node].second;

	int mid = (start + end) / 2;
	int left = evenTree(node * 2, start, mid, sidx, eidx);
	int right = evenTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
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
		int n, l, r;
		scanf("%d %d %d", &n, &l, &r);

		if (n == 1) {
			if (arr[l] % 2 == 0 && r % 2 != 0) {
				modifyTree(1, 1, N, l, 1, -1);
			}
			else if (arr[l] % 2 != 0 && r % 2 == 0) {
				modifyTree(1, 1, N, l, -1, 1);
			}

			arr[l] = r;
		}
		else if (n == 2) {
			printf("%d\n", evenTree(1, 1, N, l, r));
		}
		else {
			printf("%d\n", oddTree(1, 1, N, l, r));
		}
	}
}
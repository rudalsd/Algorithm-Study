#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, m;
vector<int> segmentTree;
int pos[100001];

int makeTree(int node, int start, int end)		//트리 만들기
{
	if (start == end) {
		if (start <= n) {
			return segmentTree[node] = 1;
		}
		else {
			return 0;
		}
	}

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);
	int right = makeTree(node * 2 + 1, mid + 1, end);

	return segmentTree[node] = left + right;
}

void get(int node, int start, int end, int idx)	//dvd 빼기
{
	if (idx < start || idx > end) {
		return;
	}
	else {
		segmentTree[node]--;
	}

	if (start == end) return;

	int mid = (start + end) / 2;
	get(node * 2, start, mid, idx);
	get(node * 2 + 1, mid + 1, end, idx);
}

void put(int node, int start, int end, int idx)	//dvd 넣기
{
	if (idx < start || idx > end) {
		return;
	}
	else {
		segmentTree[node]++;
	}

	if (start == end) return;

	int mid = (start + end) / 2;
	put(node * 2, start, mid, idx);
	put(node * 2 + 1, mid + 1, end, idx);
}

int sum(int node, int start, int end, int sidx, int eidx)	//합 구하기
{
	if (sidx > end || eidx < start) return 0;
	if (sidx <= start && end <= eidx) return segmentTree[node];

	int mid = (start + end) / 2;
	int left = sum(node * 2, start, mid, sidx, eidx);
	int right = sum(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			pos[i] = n - i + 1;
		}
		int size = (1 << (int)ceil(log2(n + m)) + 1);
		segmentTree.clear();
		segmentTree.resize(size);
		makeTree(1, 1, n + m);

		for (int i = 1; i <= m; i++) {
			int num;
			scanf("%d", &num);
			get(1, 1, n + m, pos[num]);
			printf("%d ", sum(1, 1, n + m, pos[num], n + m));
			put(1, 1, n + m, n + i);
			pos[num] = n + i;
		}
		printf("\n");
	}
}
#include<iostream>
#include<cmath>

#define ll long long

using namespace std;

int n;
int segTree[300000];
ll arr[100001];
ll ans;

int makeTree(int node, int start, int end)		//세그먼트 트리 만들기
{
	if (start == end) {		//리프노드
		return segTree[node] = start;
	}

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);		//왼쪽 자식 노드
	int right = makeTree(node * 2 + 1, mid + 1, end);	//오른쪽 자식 노드

	return segTree[node] = arr[left] > arr[right] ? right : left;
}

int find(int node, int start, int end, int sidx, int eidx)	//최소 높이의 idx return
{
	if (eidx < start || sidx > end) return 0;	//범위에 완전히 포함되지 않을 때
	if (start >= sidx && end <= eidx) return segTree[node];	//범위에 완전히 포함될 때
	//범위에 일부 포함될 때
	int mid = (start + end) / 2;
	int left = find(node * 2, start, mid, sidx, eidx);
	int right = find(node * 2 + 1, mid + 1, end, sidx, eidx);

	if (left == 0) return right;
	if (right == 0) return left;
	return arr[left] > arr[right] ? right : left;
}

void getMax(int start, int end)
{
	if (start > end) return;
	int min = find(1, 1, n, start, end);

	ll W = arr[min] * (end - start + 1);
	ans = max(ans, W);

	getMax(start, min - 1);
	getMax(min + 1, end);
}

int main()
{
	while (1)
	{
		ans = 0;
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
		}

		makeTree(1, 1, n);

		getMax(1, n);

		printf("%lld\n", ans);
	}
}
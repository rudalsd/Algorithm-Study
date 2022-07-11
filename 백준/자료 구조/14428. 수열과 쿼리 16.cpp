#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int num;
	int idx;
};

int N, M;
int arr[100001];
vector<node> segTree;

node makeTree(int cur, int start, int end)	//세그먼트 트리 만들기
{
	int mid = (start + end) / 2;
	if (start == end) {
		return segTree[cur] = { arr[start], start };
	}

	node left = makeTree(cur * 2, start, mid);	//왼쪽 자식 노드
	node right = makeTree(cur * 2 + 1, mid + 1, end);	//오른쪽 자식 노드

	if (left.num < right.num) {
		return segTree[cur] = { left.num, left.idx };
	}
	else if (right.num < left.num) {
		return segTree[cur] = { right.num, right.idx };
	}
	else {
		if (left.idx < right.idx) {
			return segTree[cur] = { left.num, left.idx };
		}
		else {
			return segTree[cur] = { right.num, right.idx };
		}
	}
}

node updateTree(int cur, int start, int end, int idx)	//세그먼트 트리 업데이트
{
	if (idx < start || idx > end) {		//start ~ end에 idx가 포함되어 있지 않을 때
		return segTree[cur];
	}
	if (start == end) {		//바꿀 숫자의 idx에 도착했을 때
		return segTree[cur] = { arr[start], start };
	}

	int mid = (start + end) / 2;
	node left = updateTree(cur * 2, start, mid, idx);	//왼쪽 자식 노드
	node right = updateTree(cur * 2 + 1, mid + 1, end, idx);	//오른쪽 자식 노드

	if (left.num < right.num) {
		return segTree[cur] = { left.num, left.idx };
	}
	else if (right.num < left.num) {
		return segTree[cur] = { right.num, right.idx };
	}
	else {
		if (left.idx < right.idx) {
			return segTree[cur] = { left.num, left.idx };
		}
		else {
			return segTree[cur] = { right.num, right.idx };
		}
	}
}

node minTree(int cur, int start, int end, int sidx, int eidx)	//최솟값 구하기
{
	if (end < sidx || start > eidx) {	//범위를 완전히 벗어났을 때
		return { 1111111111, 987654321 };
	}
	if (sidx <= start && eidx >= end) {	//범위에 완전히 포함될 때
		return segTree[cur];
	}
	//범위에 일부 포함될 때
	int mid = (start + end) / 2;

	node left = minTree(cur * 2, start, mid, sidx, eidx);
	node right = minTree(cur * 2 + 1, mid + 1, end, sidx, eidx);

	if (left.num < right.num) {
		return left;
	}
	else if (right.num < left.num) {
		return right;
	}
	else {
		if (left.idx < right.idx) {
			return left;
		}
		else {
			return right;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	int size = (1 << (int)(ceil(log2(N) + 1)));
	segTree.resize(size);
	makeTree(1, 1, N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {	//업데이트
			arr[b] = c;
			updateTree(1, 1, N, b);
		}
		else {		//최솟값의 idx출력
			node ans = minTree(1, 1, N, b, c);
			printf("%d\n", ans.idx);
		}
	}
}
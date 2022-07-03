#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int max;
	int min;
};

int N, M;
int arr[100001];	//입력받은 정수를 저장할 배열
vector<node> segTree;	//segment tree

node makeTree(int curNode, int start, int end)		//segment tree 만들기
{
	if (start == end) {		//리프 노드일 때
		return segTree[curNode] = { arr[start],arr[start] };
	}

	int mid = (start + end) / 2;
	node left = makeTree(curNode * 2, start, mid);	//왼쪽 자식 노드
	node right = makeTree(curNode * 2 + 1, mid + 1, end);	//오른쪽 자식 노드
	return segTree[curNode] = { max(left.max, right.max), min(left.min, right.min) };	//각 노드에 최솟값과 최댓값 저장
}

node findTree(int curNode, int start, int end, int sidx, int eidx)
{
	if (start > eidx || end < sidx) {	//구하고자 하는 범위를 완전히 벗어났을 때
		node cur = { 0,1111111111 };
		return cur;
	}
	if (start >= sidx && end <= eidx) {	//구하고자 하는 범위에 완전히 포함될 때
		return segTree[curNode];
	}

	int mid = (start + end) / 2;		//구하고자 하는 범위에 일부 포함될 때
	node left = findTree(curNode * 2, start, mid, sidx, eidx);		//왼쪽 자식 노드
	node right = findTree(curNode * 2 + 1, mid + 1, end, sidx, eidx);	//오른쪽 자식 노드

	node cur = { max(left.max,right.max), min(left.min,right.min) };
	return cur;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	int size = (1 << (int)(ceil(log2(N)) + 1));	//segment tree의 사이즈
	segTree.resize(size);
	makeTree(1, 1, N);		//segment tree 만들기

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node ans = findTree(1, 1, N, a, b);
		printf("%d %d\n", ans.min, ans.max);
	}
}
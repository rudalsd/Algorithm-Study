#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int max;
	int min;
};

int N, M;
int arr[100001];	//�Է¹��� ������ ������ �迭
vector<node> segTree;	//segment tree

node makeTree(int curNode, int start, int end)		//segment tree �����
{
	if (start == end) {		//���� ����� ��
		return segTree[curNode] = { arr[start],arr[start] };
	}

	int mid = (start + end) / 2;
	node left = makeTree(curNode * 2, start, mid);	//���� �ڽ� ���
	node right = makeTree(curNode * 2 + 1, mid + 1, end);	//������ �ڽ� ���
	return segTree[curNode] = { max(left.max, right.max), min(left.min, right.min) };	//�� ��忡 �ּڰ��� �ִ� ����
}

node findTree(int curNode, int start, int end, int sidx, int eidx)
{
	if (start > eidx || end < sidx) {	//���ϰ��� �ϴ� ������ ������ ����� ��
		node cur = { 0,1111111111 };
		return cur;
	}
	if (start >= sidx && end <= eidx) {	//���ϰ��� �ϴ� ������ ������ ���Ե� ��
		return segTree[curNode];
	}

	int mid = (start + end) / 2;		//���ϰ��� �ϴ� ������ �Ϻ� ���Ե� ��
	node left = findTree(curNode * 2, start, mid, sidx, eidx);		//���� �ڽ� ���
	node right = findTree(curNode * 2 + 1, mid + 1, end, sidx, eidx);	//������ �ڽ� ���

	node cur = { max(left.max,right.max), min(left.min,right.min) };
	return cur;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	int size = (1 << (int)(ceil(log2(N)) + 1));	//segment tree�� ������
	segTree.resize(size);
	makeTree(1, 1, N);		//segment tree �����

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node ans = findTree(1, 1, N, a, b);
		printf("%d %d\n", ans.min, ans.max);
	}
}
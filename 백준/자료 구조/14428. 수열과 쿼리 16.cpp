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

node makeTree(int cur, int start, int end)	//���׸�Ʈ Ʈ�� �����
{
	int mid = (start + end) / 2;
	if (start == end) {
		return segTree[cur] = { arr[start], start };
	}

	node left = makeTree(cur * 2, start, mid);	//���� �ڽ� ���
	node right = makeTree(cur * 2 + 1, mid + 1, end);	//������ �ڽ� ���

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

node updateTree(int cur, int start, int end, int idx)	//���׸�Ʈ Ʈ�� ������Ʈ
{
	if (idx < start || idx > end) {		//start ~ end�� idx�� ���ԵǾ� ���� ���� ��
		return segTree[cur];
	}
	if (start == end) {		//�ٲ� ������ idx�� �������� ��
		return segTree[cur] = { arr[start], start };
	}

	int mid = (start + end) / 2;
	node left = updateTree(cur * 2, start, mid, idx);	//���� �ڽ� ���
	node right = updateTree(cur * 2 + 1, mid + 1, end, idx);	//������ �ڽ� ���

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

node minTree(int cur, int start, int end, int sidx, int eidx)	//�ּڰ� ���ϱ�
{
	if (end < sidx || start > eidx) {	//������ ������ ����� ��
		return { 1111111111, 987654321 };
	}
	if (sidx <= start && eidx >= end) {	//������ ������ ���Ե� ��
		return segTree[cur];
	}
	//������ �Ϻ� ���Ե� ��
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

		if (a == 1) {	//������Ʈ
			arr[b] = c;
			updateTree(1, 1, N, b);
		}
		else {		//�ּڰ��� idx���
			node ans = minTree(1, 1, N, b, c);
			printf("%d\n", ans.idx);
		}
	}
}
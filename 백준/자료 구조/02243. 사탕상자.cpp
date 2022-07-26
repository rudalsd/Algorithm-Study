#include<iostream>

using namespace std;

int n;
int segTree[2111111];

void update(int node, int start, int end, int taste, int N)	//���� ���� update
{
	if (taste > end || taste < start) return;	//������ �����

	segTree[node] += N;

	if (start == end) return;	//������ ������ ���ԵǸ�

	//������ �Ϻ� ���ԵǸ�
	int mid = (start + end) / 2;
	update(node * 2, start, mid, taste, N);
	update(node * 2 + 1, mid + 1, end, taste, N);
}

int get(int node, int start, int end, int idx)	//idx��° ������ �� ���
{
	if (start == end) {		//������ ��Ȯ�� ������
		return start;
	}

	int mid = (start + end) / 2;
	if (segTree[node * 2] >= idx) return get(node * 2, start, mid, idx);	//���� �ڽ� ���
	return get(node * 2 + 1, mid + 1, end, idx - segTree[node * 2]);		//������ �ڽ� ���
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int A, B, C;
		scanf("%d", &A);

		if (A == 1) {		//���� ������
			scanf("%d", &B);
			int idx = get(1, 1, 1000000, B);
			printf("%d\n", idx);
			update(1, 1, 1000000, idx, -1);
		}
		else {				//���� �ְ�, ����
			scanf("%d %d", &B, &C);
			update(1, 1, 1000000, B, C);
		}
	}
}
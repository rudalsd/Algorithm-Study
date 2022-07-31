#include<iostream>
#include<cmath>

#define ll long long

using namespace std;

int n;
int segTree[300000];
ll arr[100001];
ll ans;

int makeTree(int node, int start, int end)		//���׸�Ʈ Ʈ�� �����
{
	if (start == end) {		//�������
		return segTree[node] = start;
	}

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);		//���� �ڽ� ���
	int right = makeTree(node * 2 + 1, mid + 1, end);	//������ �ڽ� ���

	return segTree[node] = arr[left] > arr[right] ? right : left;
}

int find(int node, int start, int end, int sidx, int eidx)	//�ּ� ������ idx return
{
	if (eidx < start || sidx > end) return 0;	//������ ������ ���Ե��� ���� ��
	if (start >= sidx && end <= eidx) return segTree[node];	//������ ������ ���Ե� ��
	//������ �Ϻ� ���Ե� ��
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
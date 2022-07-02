#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
long long arr[1000001];			//������ ������ �迭
vector<long long> segTree;

int N, M, K;

long long makeTree(int node, int start, int end)	//segmentTree�� ����� �Լ�
{
	if (start == end) {		//���� ���
		return segTree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	long long left = makeTree(node * 2, start, mid);	//���� ���
	long long right = makeTree(node * 2 + 1, mid + 1, end);	//������ ���

	return segTree[node] = left + right;
}

void changeTree(int node, int start, int end, int idx, long long diff)	//���ϴ� idx �� �ٲٱ�
{
	if (start > idx || end < idx) return;	//�ٲٰ��� �ϴ� idx�� ���� ���� ������ return
	segTree[node] += diff;			//idx�� ���� ���� ������ ���̸�ŭ ������

	if (start != end) {				//���� ��尡 �ƴ� ��
		int mid = (start + end) / 2;
		changeTree(node * 2, start, mid, idx, diff);	//���� ���
		changeTree(node * 2 + 1, mid + 1, end, idx, diff);	//������ ���
	}
}

long long sumTree(int node, int start, int end, int sidx, int eidx)	//sidx ~ eidx������ ��
{
	if (eidx < start || sidx > end) return 0;	//������ ����� 0 return
	if (sidx <= start && eidx >= end) return segTree[node];	//������ ���� ���ԵǸ� �ش� ��� �� return

	int mid = (start + end) / 2;
	long long left = sumTree(node * 2, start, mid, sidx, eidx);	//���� ���
	long long right = sumTree(node * 2 + 1, mid + 1, end, sidx, eidx);	//������ ���
	return left + right;
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	int size = 1 << (int)(ceil(log2(N)) + 1);

	segTree.resize(size);
	makeTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {		//�� �ٲٱ�
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			long long diff = c - arr[b];	//�ٲٰ��� �ϴ� ���� ���� ���� ��
			arr[b] = c;			//���ϴ� idx�� �� ����
			changeTree(1, 1, N, b, diff);
		}
		else {		//������ ���ϱ�
			int b, c;
			scanf("%d %d", &b, &c);
			long long ans = sumTree(1, 1, N, b, c);
			printf("%lld\n", ans);
		}
	}
}
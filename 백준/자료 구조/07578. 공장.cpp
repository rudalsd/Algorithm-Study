#include<iostream>
#include<cmath>

#define ll long long

using namespace std;

int N;
int A[1000001];
ll segTree[1111111];

ll getSum(int node, int start, int end, int sidx, int eidx)		//���� idx������ ū ������ ���� return
{
	if (sidx > end || eidx < start) return 0;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	ll left = getSum(node * 2, start, mid, sidx, eidx);
	ll right = getSum(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}

ll update(int node, int start, int end, int idx)		//���� idx�� �߰�
{
	if (idx < start || idx > end) return segTree[node];
	segTree[node]++;
	if (start == end) return segTree[node];

	int mid = (start + end) / 2;
	ll left = update(node * 2, start, mid, idx);
	ll right = update(node * 2 + 1, mid + 1, end, idx);

	return segTree[node] = left + right;
}

int main()
{
	scanf("%d", &N);

	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		A[num] = i;
	}

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		int idx = A[num];
		ans += getSum(1, 1, N, idx + 1, N);	//���� idx���� ū ������ ���� ans�� ���ϱ�
		update(1, 1, N, idx);	//���� idx���� �־��ֱ�
	}

	printf("%lld", ans);
}
#include<iostream>
#include<vector>
#include<cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

int N, M, K;
vector<ll> segTree;
ll arr[1000001];

ll makeTree(int node, int start, int end)		//Ʈ�� �����
{
	if (start == end) return segTree[node] = arr[start];
	int mid = (start + end) / 2;

	ll left = makeTree(node * 2, start, mid);	//���� �ڽ� ���
	ll right = makeTree(node * 2 + 1, mid + 1, end);	//������ �ڽ� ���

	return segTree[node] = ((left % MOD) * (right % MOD)) % MOD;
}

ll gopTree(int node, int start, int end, int sidx, int eidx)	//sidx ~ eidx ������ ��
{
	if (end < sidx || start > eidx) return 1;	//������ �����
	if (sidx <= start && eidx >= end) return segTree[node];	//������ ������ ���ԵǸ�
	//������ �Ϻ� ���ԵǸ�
	int mid = (start + end) / 2;

	ll left = gopTree(node * 2, start, mid, sidx, eidx);	//���� �ڽ� ���
	ll right = gopTree(node * 2 + 1, mid + 1, end, sidx, eidx);	//������ �ڽ� ���

	return ((left % MOD) * (right % MOD)) % MOD;
}

ll changeTree(int node, int start, int end, int idx)
{
	if (idx < start || idx > end) return segTree[node];	//idx�� ������ ���Ե��� ������
	if (start == end) {				//�ٲٰ��� �ϴ� ��忡 �����ϸ�
		return segTree[node] = arr[idx];
	}
	//idx�� ������ ���ԵǸ�
	int mid = (start + end) / 2;

	ll left = changeTree(node * 2, start, mid, idx);	//���� �ڽ� ���
	ll right = changeTree(node * 2 + 1, mid + 1, end, idx);	//������ �ڽ� ���

	return segTree[node] = ((left % MOD) * (right % MOD)) % MOD;

}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	int size = (1 << (int)(ceil(log2(N)) + 1));	//Ʈ�� ������ ���ϱ�
	segTree.resize(size);
	makeTree(1, 1, N);		//Ʈ�� �����

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {		//���� �ٲٱ�
			arr[b] = (ll)c;
			changeTree(1, 1, N, b);
		}
		else {				//���� �� ���ϱ�
			ll ans = gopTree(1, 1, N, b, c);
			ans %= MOD;
			printf("%lld\n", ans);
		}
	}
}
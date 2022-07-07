#include<iostream>
#include<vector>
#include<cmath>

#define ll long long
#define MOD 1000000007

using namespace std;

int N, M, K;
vector<ll> segTree;
ll arr[1000001];

ll makeTree(int node, int start, int end)		//트리 만들기
{
	if (start == end) return segTree[node] = arr[start];
	int mid = (start + end) / 2;

	ll left = makeTree(node * 2, start, mid);	//왼쪽 자식 노드
	ll right = makeTree(node * 2 + 1, mid + 1, end);	//오른쪽 자식 노드

	return segTree[node] = ((left % MOD) * (right % MOD)) % MOD;
}

ll gopTree(int node, int start, int end, int sidx, int eidx)	//sidx ~ eidx 사이의 곱
{
	if (end < sidx || start > eidx) return 1;	//범위를 벗어나면
	if (sidx <= start && eidx >= end) return segTree[node];	//범위에 완전히 포함되면
	//범위에 일부 포함되면
	int mid = (start + end) / 2;

	ll left = gopTree(node * 2, start, mid, sidx, eidx);	//왼쪽 자식 노드
	ll right = gopTree(node * 2 + 1, mid + 1, end, sidx, eidx);	//오른쪽 자식 노드

	return ((left % MOD) * (right % MOD)) % MOD;
}

ll changeTree(int node, int start, int end, int idx)
{
	if (idx < start || idx > end) return segTree[node];	//idx가 범위에 포함되지 않으면
	if (start == end) {				//바꾸고자 하는 노드에 도착하면
		return segTree[node] = arr[idx];
	}
	//idx가 범위에 포함되면
	int mid = (start + end) / 2;

	ll left = changeTree(node * 2, start, mid, idx);	//왼쪽 자식 노드
	ll right = changeTree(node * 2 + 1, mid + 1, end, idx);	//오른쪽 자식 노드

	return segTree[node] = ((left % MOD) * (right % MOD)) % MOD;

}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	int size = (1 << (int)(ceil(log2(N)) + 1));	//트리 사이즈 구하기
	segTree.resize(size);
	makeTree(1, 1, N);		//트리 만들기

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) {		//숫자 바꾸기
			arr[b] = (ll)c;
			changeTree(1, 1, N, b);
		}
		else {				//구간 곱 구하기
			ll ans = gopTree(1, 1, N, b, c);
			ans %= MOD;
			printf("%lld\n", ans);
		}
	}
}
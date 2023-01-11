#include<iostream>
#define ll long long

using namespace std;

int N, M, K;
ll arr[1000001];
ll segTree[2100000];
ll lazy[2100000];	//방문할 필요가 없는 노드의 경우 다음 방문 때 더할 값을 저장

void makeTree(int node, int start, int end)
{
	if (start == end) {
		segTree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	makeTree(node * 2, start, mid);
	makeTree(node * 2 + 1, mid + 1, end);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void modifyLazy(int node, int start, int end)	//현재 노드에 lazy 값이 있다면 더해주기
{
	if (lazy[node] != 0) {
		segTree[node] += (ll)(end - start + 1) * lazy[node];
		if (start != end) {	//리프 노드가 아니라면 아래 노드에 lazy값 물려주기
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void modifyTree(int node, int start, int end, int sidx, int eidx, ll d)
{
	modifyLazy(node, start, end);	//현재 노드에 lazy값 체크

	if (sidx > end || start > eidx) return;

	if (sidx <= start && end <= eidx) {	//완전히 포함된다면
		segTree[node] += (ll)(end - start + 1) * d;
		if (start != end) {	//리프 노드가 아닐 경우 아래 노드에 lazy값 물려주기
			lazy[node * 2] += d;
			lazy[node * 2 + 1] += d;
		}
		return;
	}

	int mid = (start + end) / 2;
	modifyTree(node * 2, start, mid, sidx, eidx, d);
	modifyTree(node * 2 + 1, mid+1, end, sidx, eidx, d);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

ll sumTree(int node, int start, int end, int sidx, int eidx)
{
	modifyLazy(node, start, end);	//현재 노드에 lazy값 체크

	if (start > eidx || end < sidx) return 0;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	ll left = sumTree(node * 2, start, mid, sidx, eidx);
	ll right = sumTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	makeTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);

		if (a == 1) {
			int b, c;
			ll d;
			scanf("%d %d %lld", &b, &c, &d);

			modifyTree(1, 1, N, b, c, d);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);

			printf("%lld\n", sumTree(1, 1, N, b, c));
		}
	}
}
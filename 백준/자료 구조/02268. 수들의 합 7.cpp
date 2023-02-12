#include<iostream>
#define ll long long

using namespace std;

int N, M;
ll segTree[2100000];
int arr[1000001];

ll sum(int node, int start, int end, int sidx, int eidx)
{
	if (end < sidx || start > eidx) return 0;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	ll left = sum(node * 2, start, mid, sidx, eidx);
	ll right = sum(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left + right;
}


void modify(int node, int start, int end, int idx, int diff)
{
	if (idx < start || idx > end) return;
	segTree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		modify(node * 2, start, mid, idx, diff);
		modify(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0) {
			if (b < c) {
				printf("%lld\n", sum(1, 1, N, b, c));
			}
			else {
				printf("%lld\n", sum(1, 1, N, c, b));
			}
		}
		else {
			int diff = c - arr[b];
			arr[b] = c;
			modify(1,1,N,b,diff);
		}
	}
}
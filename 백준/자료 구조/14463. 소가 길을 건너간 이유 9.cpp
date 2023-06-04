#include<iostream>
#define ll long long

using namespace std;

int N;
int visited[50001];
ll segTree[200000];

void updateTree(int idx, int diff)
{
	while (idx != 0) {
		segTree[idx] += diff;
		idx >>= 1;
	}
}

ll getTree(int L, int R)
{
	ll ret = 0;

	while (L <= R) {
		if (L & 1) {
			ret += segTree[L];
			L++;
		}
		if (~R & 1) {
			ret += segTree[R];
			R--;
		}

		L >>= 1;
		R >>= 1;
	}

	return ret;
}

int main()
{
	scanf("%d", &N);

	ll ans = 0;

	for (int i = 1; i <= 2 * N; i++) {
		int a;
		scanf("%d", &a);

		if (visited[a] == 0) {
			visited[a] = i;
			updateTree(2 * N + i - 1, 1);
		}
		else {
			ans += getTree(2 * N + visited[a], 2 * N + i - 2);
			updateTree(2 * N + visited[a] - 1, -1);
		}
	}

	printf("%lld", ans);
}
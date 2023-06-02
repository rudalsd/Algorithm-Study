#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[100000];
int cntL[100000];
int cntR[100000];
int segTree[200000];
vector<int> h;
int ret;

void updateTree(int idx)
{
	while (idx != 0) {
		segTree[idx]++;
		idx >>= 1;
	}
}

int getTree(int L, int R)
{
	int ret = 0;

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

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		h.push_back(arr[i]);
	}

	sort(h.begin(), h.end());

	for (int i = 0; i < N; i++) {
		auto idx = lower_bound(h.begin(), h.end(), arr[i]) - h.begin();
		updateTree(idx + N);

		cntL[i] = getTree(N + idx + 1, 2 * N - 1);
	}

	fill(segTree, segTree + 2 * N, 0);

	for (int i = N - 1; i >= 0; i--) {
		auto idx = lower_bound(h.begin(), h.end(), arr[i]) - h.begin();
		updateTree(idx + N);

		cntR[i] = getTree(N + idx + 1, 2 * N - 1);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int L = cntL[i];
		int R = cntR[i];

		if (L > R) {
			swap(L, R);
		}

		if (2 * L < R) ans++;
	}

	printf("%d", ans);
}

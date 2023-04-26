#include<iostream>
#define ll long long

using namespace std;

int N, K;
int segTree[262222];
int arr[250000];
ll ans;

void plusTree(int node, int s, int e, int num)
{
	if (s > num || e < num) return;
	segTree[node]++;
	
	if (s != e) {
		int m = (s + e) / 2;

		plusTree(node * 2, s, m, num);
		plusTree(node * 2 + 1, m + 1, e, num);
	}
}

void minusTree(int node, int s, int e, int num)
{
	if (s > num || e < num) return;
	segTree[node]--;

	if (s != e) {
		int m = (s + e) / 2;

		minusTree(node * 2, s, m, num);
		minusTree(node * 2 + 1, m + 1, e, num);
	}
}

void getTree(int node, int s, int e, int cnt)
{
	if (s == e) {
		ans += s;
		return;
	}

	int m = (s + e) / 2;

	if (segTree[node * 2] >= cnt) {
		getTree(node * 2, s, m, cnt);
	}
	else {
		getTree(node * 2 + 1, m + 1, e, cnt - segTree[node * 2]);
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	int Max = 0;
	int Min = 66666;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		Max = max(Max, arr[i]);
		Min = min(Min, arr[i]);
	}

	for (int i = 0; i < K; i++) {
		plusTree(1, Min, Max, arr[i]);
	}

	getTree(1, Min, Max, (K + 1) / 2);

	for (int i = K; i < N; i++) {
		plusTree(1, Min, Max, arr[i]);
		minusTree(1, Min, Max, arr[i-K]);
		getTree(1, Min, Max, (K + 1) / 2);
	}

	printf("%lld", ans);
}
#include<iostream>
#define ll long long

using namespace std;

int N, Q, S, T;
ll arr[200001];
ll diff[200000];
ll segTree[400000];

void updateTree(int i)
{
	if (diff[i] < 0) {
		segTree[i + N] = diff[i] * S;
	}
	else {
		segTree[i + N] = diff[i] * T;
	}

	int temp = i + N;
	temp >>= 1;
	while (temp != 0) {
		segTree[temp] = segTree[temp << 1] + segTree[temp << 1 | 1];
		temp >>= 1;
	}
}

int main()
{
	scanf("%d %d %d %d", &N, &Q, &S, &T);

	for (int i = 0; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		diff[i] = arr[i] - arr[i + 1];
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < arr[i + 1]) {
			segTree[i + N] = (arr[i] - arr[i + 1]) * S;
		}
		else {
			segTree[i + N] = (arr[i] - arr[i + 1]) * T;
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
	}

	for (int i = 0; i < Q; i++) {
		int L, R;
		ll X;
		scanf("%d %d %lld", &L, &R, &X);

		diff[L - 1] -= X;
		if(R != N) diff[R] += X;

		updateTree(L - 1);
		if (R != N) updateTree(R);
		printf("%lld\n", segTree[1]);
	}
}
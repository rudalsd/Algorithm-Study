#include<iostream>

using namespace std;

int N, K;
int arr[10];
int ans;

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		while (K >= arr[i]) {
			K -= arr[i];
			ans++;
		}
		if (K == 0) break;
	}

	printf("%d", ans);
}
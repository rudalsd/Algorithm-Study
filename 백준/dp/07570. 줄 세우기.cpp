#include<iostream>

using namespace std;

int N;
int arr[1000000];
int cnt[1000001];
int ans;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		cnt[arr[i]] = cnt[arr[i] - 1] + 1;
		ans = max(ans, cnt[arr[i]]);
	}

	printf("%d", N - ans);
}
#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[100000];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int s = N-2;
	int e = N - 1;
	int ans = 2000000001;

	while (s >= 0) {
		int temp = arr[e] - arr[s];

		if (temp >= M) {
			ans = min(ans, temp);
			e--;
		}
		else {
			s--;
		}
	}

	printf("%d", ans);
}
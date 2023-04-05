#include<iostream>

using namespace std;

int N, K;
int arr[1000000];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int s, e;
	s = e = 0;
	int cnt = 0;
	int ans = 1;

	if (arr[0] % 2 == 1) {
		cnt = 1;
		ans = 0;
	}

	while (s <= e && e < N) {

		if (cnt <= K || s == e) {
			e++;
			if (arr[e] % 2 == 1) cnt++;
		}
		else {
			if (arr[s] % 2 == 1)cnt--;
			s++;
		}

		if (e < N) {
			ans = max(ans, e - s + 1 - cnt);
		}
	}

	printf("%d", ans);
}
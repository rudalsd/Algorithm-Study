#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int arr[600];
int ans = 2011111111;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N ; i++) {
		for (int j = i + 1; j < N ; j++) {
			int H = arr[i] + arr[j];
			int s, e;
			s = i + 1;
			e = N - 1;
			while (s < e) {
				int temp = arr[s] + arr[e];

				if (s == i || s == j) {
					s++;
					continue;
				}
				if (e == i || e == j) {
					e--;
					continue;
				}

				ans = min(ans, abs(H - temp));

				if (ans == 0) {
					printf("0");
					return 0;
				}

				if (H - temp > 0) {
					s++;
				}
				else {
					e--;
				}
			}
		}
	}

	printf("%d", ans);
}
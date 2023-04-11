#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int N;
int arr[2000];
map<int, int> m;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (m[arr[i]] > 0) {
			ans++;
			continue;
		}

		int s = 0;
		int e = N - 1;

		while (s < e) {
			if (s == i) {
				s++;
				continue;
			}
			if (e == i) {
				e--;
				continue;
			}

			if (arr[i] == arr[s] + arr[e]) {
				m[arr[i]]++;
				ans++;
				break;
			}
			else if (arr[i] > arr[s] + arr[e]) {
				s++;
			}
			else {
				e--;
			}
		}
	}

	printf("%d", ans);
}
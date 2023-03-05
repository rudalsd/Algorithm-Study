#include<iostream>

using namespace std;

int C, N;
pair<int, int> arr[20];
int cus[1111];
int ans = 987654321;

int main()
{
	scanf("%d %d", &C, &N);

	fill(cus + 1, cus + 1111, 987654321);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < C; j++) {
			cus[j + arr[i].second] = min(cus[j + arr[i].second], cus[j] + arr[i].first);

			if (j + arr[i].second >= C) {
				ans = min(ans, cus[j + arr[i].second]);
			}
		}
	}

	printf("%d", ans);
}
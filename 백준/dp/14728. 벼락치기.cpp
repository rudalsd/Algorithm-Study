#include<iostream>

using namespace std;

int N, T;
pair<int, int> arr[101];
int ans[101][10001];

int main()
{
	scanf("%d %d", &N, &T);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	for (int i = 1; i <= N; i++) {
		int cost = arr[i].first;
		int point = arr[i].second;

		for (int j = 1; j <= T; j++) {
			if (j < cost) {
				ans[i][j] = ans[i - 1][j];
			}
			else {
				ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - cost] + point);
			}
		}
	}

	printf("%d", ans[N][T]);
}
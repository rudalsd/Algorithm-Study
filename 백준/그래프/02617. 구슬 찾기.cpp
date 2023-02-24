#include<iostream>

using namespace std;

int N, M;
int arr[100][100];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a][b] = 1;
		arr[b][a] = -1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][i] == arr[i][k] && arr[j][i] != 0) {
					arr[j][k] = arr[j][i];
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int cnt[2] = { 0 };
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				cnt[0]++;
			}
			else if (arr[i][j] == -1) {
				cnt[1]++;
			}
		}
		if (cnt[0] >= (N + 1) / 2 || cnt[1] >= (N + 1) / 2) {
			ans++;
		}
	}

	printf("%d", ans);
}
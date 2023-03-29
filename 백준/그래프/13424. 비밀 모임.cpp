#include<iostream>

using namespace std;

int arr[101][101];
int room[101];

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N, M, K;
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					arr[i][j] = 0;
				}
				else {
					arr[i][j] = 987654321;
				}
			}
		}

		for (int i = 0; i < M; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			arr[a][b] = c;
			arr[b][a] = c;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}

		scanf("%d", &K);
		int dist = 987654321;
		int ans = 0;

		for (int i = 0; i < K; i++) {
			scanf("%d", &room[i]);
		}

		for (int i = 1; i <= N; i++) {
			int temp = 0;
			for (int j = 0; j < K; j++) {
				temp += arr[i][room[j]];
			}
			if (dist > temp) {
				dist = temp;
				ans = i;
			}
		}

		printf("%d\n", ans);
	}
}
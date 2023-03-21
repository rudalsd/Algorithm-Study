#include<iostream>

using namespace std;

int N, M, T;
int arr[301][301];

int main()
{
	scanf("%d %d %d", &N, &M, &T);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < M; i++) {
		int u, v, h;
		scanf("%d %d %d", &u, &v, &h);

		arr[u][v] = h;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				arr[j][k] = min(arr[j][k], max(arr[j][i], arr[i][k]));
			}
		}
	}

	for (int i = 0; i < T; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		if (arr[u][v] == 987654321) {
			printf("-1\n");
		}
		else {
			printf("%d\n", arr[u][v]);
		}
	}
}
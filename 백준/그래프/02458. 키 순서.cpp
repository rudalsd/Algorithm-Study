#include<iostream>

using namespace std;

int N, M;
int arr[501][501];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int flag = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				if (arr[i][j] == 987654321 && arr[j][i] == 987654321) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) ans++;
	}

	printf("%d", ans);
}
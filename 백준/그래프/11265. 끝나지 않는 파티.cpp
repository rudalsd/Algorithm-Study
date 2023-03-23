#include<iostream>

using namespace std;

int N, M;
int arr[501][501];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);

		if (arr[A][B] > C) {
			printf("Stay here\n");
		}
		else {
			printf("Enjoy other party\n");
		}
	}
}
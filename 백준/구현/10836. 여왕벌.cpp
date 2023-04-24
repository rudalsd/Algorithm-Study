#include<iostream>

using namespace std;

int M, N;
int arr[1400];

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		int n[3];
		int idx = 1;
		scanf("%d %d %d", &n[0], &n[1], &n[2]);

		for (int i = n[0]; i < n[0] + n[1]; i++) {
			arr[i] += 1;
		}

		for (int i = n[0] + n[1]; i < 2 * M - 1; i++) {
			arr[i] += 2;
		}
	}

	for (int i = M - 1; i >= 0; i--) {
		printf("%d ", arr[i] + 1);
		for (int j = M; j < 2 * M - 1; j++) {
			printf("%d ", arr[j] + 1);
		}
		printf("\n");
	}
}
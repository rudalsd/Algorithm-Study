#include<iostream>

using namespace std;

int N;
int arr[21][21];
int ans[21][21];

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					printf("-1");
					return 0;
				}
				else if (arr[j][k] == arr[j][i] + arr[i][k]) {
					if (ans[j][k] != -1 && ans[j][i] != -1 && ans[i][k] != -1) {
						ans[j][k] = -1;
						ans[j][i] = arr[j][i];
						ans[i][k] = arr[i][k];
					}
				}
			}
		}
	}

	int ret = 0;

	for (int i = 1; i < N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (ans[i][j] != -1) {
				ret += ans[i][j];
			}
		}
	}

	printf("%d", ret);
}
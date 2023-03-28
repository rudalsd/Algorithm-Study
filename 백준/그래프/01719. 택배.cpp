#include<iostream>

using namespace std;

int n, m;
int arr[201][201];
int ans[201][201];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				arr[i][j] = 987654321;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		ans[a][b] = b;
		ans[b][a] = a;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] != 0 && arr[i][k] != 0) {
					if (arr[j][k] > arr[j][i] + arr[i][k]) {
						arr[j][k] = arr[j][i] + arr[i][k];
						ans[j][k] = ans[j][i];
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				printf("- ");
			}
			else {
				printf("%d ", ans[i][j]);
			}
		}
		printf("\n");
	}
}
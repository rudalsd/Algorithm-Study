#include<iostream>

using namespace std;

int n, m;
int arr[251][251];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		arr[i][i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);

		if (b == 0) {
			arr[u][v] = 1;
			arr[v][u] = -1;
		}
		else {
			arr[u][v] = arr[v][u] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] != 0 && arr[i][k] != 0) {
					if (arr[j][i] > 0 && arr[i][k] > 0) {
						arr[j][k] = 1;
					}
					else if (arr[j][i] < 0 && arr[i][k] < 0) {
						if (arr[j][k] != 0) {
							arr[j][k] = max(arr[j][k], arr[j][i] + arr[i][k]);
						}
						else {
							arr[j][k] = arr[j][i] + arr[i][k];
						}
					}
					else if (arr[j][i] < 0) {
						if (arr[j][k] != 0) {
							arr[j][k] = max(arr[j][k], arr[j][i]);
						}
						else {
							arr[j][k] = arr[j][i];
						}
					}
					else if (arr[i][k] < 0) {
						if (arr[j][k] != 0) {
							arr[j][k] = max(arr[j][k], arr[i][k]);
						}
						else {
							arr[j][k] = arr[i][k];
						}
					}
				}
			}
		}
	}

	int k;

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int s, e;
		scanf("%d %d", &s, &e);

		if (arr[s][e] > 0) {
			printf("0\n");
		}
		else {
			printf("%d\n", -arr[s][e]);
		}
	}
}
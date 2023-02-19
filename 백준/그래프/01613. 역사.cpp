#include<iostream>

using namespace std;

int n, k, s;
int arr[401][401];

int main()
{
	scanf("%d %d ", &n, &k);

	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = -1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[j][i] == 0) continue;

			for (int k = 1; k <= n; k++) {
				if (arr[j][i] == arr[i][k]) {
					arr[j][k] = arr[j][i];
				}
			}
		}
	}

	scanf("%d", &s);

	for (int i = 0; i < s; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[a][b]);
	}
}
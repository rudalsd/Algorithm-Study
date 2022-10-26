#include<iostream>

using namespace std;

int V, E;
int arr[401][401];

int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		arr[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {		//플로이드 와샬
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	int ans = 987654321;

	for (int i = 1; i <= V; i++) {	//사이클의 최소 길이
		ans = min(ans, arr[i][i]);
	}

	if (ans == 987654321) {
		ans = -1;
	}
	printf("%d", ans);
}
#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[51][51];
int point[51];
vector<int> ans;

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				arr[i][j] = 9999;
			}
		}
	}

	while (1) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == -1 && b == -1) break;

		arr[a][b] = 1;
		arr[b][a] = 1;
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

	int min = 9999;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			point[i] = max(point[i], arr[i][j]);
		}

		if (min > point[i]) {
			min = point[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (min == point[i]) {
			ans.push_back(i);
		}
	}

	printf("%d %d\n", min, (int)ans.size());

	for (int next : ans) {
		printf("%d ", next);
	}
}
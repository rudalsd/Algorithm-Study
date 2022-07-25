#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int arr[8];
int visited[8];
int bucket[8];

void dfs(int level)
{
	if (level == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", bucket[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		bucket[level] = arr[i];
		visited[i] = 1;
		dfs(level + 1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	dfs(0);
}
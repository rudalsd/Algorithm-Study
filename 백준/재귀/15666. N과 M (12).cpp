#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int N, M;
int arr[10001];
int bucket[8];

void dfs(int level, int num)
{
	if (level == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", bucket[i]);
		}
		printf("\n");
		return;
	}

	for (int i = num; i <= 10000; i++) {
		if (arr[i] == 0) continue;
		bucket[level] = i;
		dfs(level + 1, i);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr[a]++;
	}

	dfs(0, 0);
}
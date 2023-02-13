#include<iostream>
#include<vector>

using namespace std;

int N;
int cost[10001];
int ans;

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int c, n;
		scanf("%d %d", &c, &n);
		if (n == 0) cost[i] = c;
		for (int j = 0; j < n; j++) {
			int task;
			scanf("%d", &task);
			cost[i] = max(cost[i], cost[task] + c);
		}
		ans = max(ans, cost[i]);
	}

	printf("%d", ans);
}
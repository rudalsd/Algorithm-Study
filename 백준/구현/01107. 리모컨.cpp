#include<iostream>
#include<cmath>

using namespace std;

int N, M;
int arr[10];
int digit;
int ans = 987654321;

void dfs(int level, int cur)
{
	ans = min(ans, abs(N - cur) + level);

	if (level == digit + 1)
	{
		return;
	}

	if (level == 0) {
		cur = 0;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] != 1) {
			cur *= 10;
			cur += i;
			dfs(level + 1, cur);
			cur -= i;
			cur /= 10;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		arr[num] = 1;
	}

	if (N == 100) {
		printf("%d", 0);
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		if (N < pow(10, i)) {
			digit = i;
			break;
		}
	}

	dfs(0, 100);

	printf("%d", ans);
}
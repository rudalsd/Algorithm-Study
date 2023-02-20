#include<iostream>
#include<queue>

using namespace std;

int N, A, B;
int arr[500001];

int main()
{
	scanf("%d %d %d", &N, &A, &B);
	fill(arr, arr + N + 1, -1);

	queue<pair<int, int>> q;

	q.push({ A,0 });
	q.push({ B,0 });

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		if (arr[cur] == cnt) {
			printf("%d", cnt);
			return 0;
		}

		arr[cur] = cnt;

		const int next = 1 << cnt;

		if (cur - next > 0) {
			q.push({ cur - next, cnt + 1 });
		}
		if (cur + next <= N) {
			q.push({ cur + next, cnt + 1 });
		}
	}

	printf("-1");
}
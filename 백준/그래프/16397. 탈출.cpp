#include<iostream>
#include<queue>

using namespace std;

int N, T, G;
int visited[100001];

int buttonB(int num)
{
	num *= 2;

	int temp = 100000;

	while (num < temp) temp /= 10;

	num -= temp;

	return num;
}

int main()
{
	scanf("%d %d %d", &N, &T, &G);

	queue<pair<int, int>>q;

	q.push({ N,0 });

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		if (visited[cur] == 1 || cur > 99999 || cnt > T) continue;
		visited[cur] = 1;

		if (cur == G) {
			printf("%d", cnt);
			return 0;
		}

		if (visited[cur + 1] != 1) {
			q.push({ cur + 1,cnt + 1 });
		}

		if (cur < 50000) {
			const int B = buttonB(cur);

			if (visited[B] != 1) {
				q.push({ B,cnt + 1 });
			}
		}
	}

	printf("ANG");
}
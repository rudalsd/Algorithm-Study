#include<iostream>
#include<queue>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	queue<pair<int, int>> q;
	q.push({ S,0 });
	visited[S] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == G) {
			printf("%d", cnt);
			return 0;
		}

		if (cur + U <= F) {
			if (visited[cur + U] == 0) {
				visited[cur + U] = 1;
				q.push({ cur + U,cnt + 1 });
			}
		}
		if (cur - D > 0) {
			if (visited[cur - D] == 0) {
				visited[cur - D] = 1;
				q.push({ cur - D,cnt + 1 });
			}
		}
	}

	printf("use the stairs");
}
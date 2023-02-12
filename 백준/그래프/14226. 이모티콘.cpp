#include<iostream>
#include<queue>

using namespace std;

int S;
int visited[2001][2001];

struct node {
	int cur;
	int copy;
	int cnt;
};

int main()
{
	scanf("%d", &S);

	queue<node> q;

	q.push({ 1,0,0 });

	while (!q.empty()) {
		const int cur = q.front().cur;
		const int copy = q.front().copy;
		const int cnt = q.front().cnt;
		q.pop();

		if(cur > 2000) continue;
		if (visited[cur][copy] == 1) continue;
		visited[cur][copy] = 1;

		if (S == cur) {
			printf("%d", cnt);
			return 0;
		}

		q.push({ cur,cur,cnt + 1 });
		q.push({ cur + copy,copy,cnt + 1 });
		if (cur - 1 > 0) {
			q.push({ cur - 1,copy,cnt + 1 });
		}
	}
}
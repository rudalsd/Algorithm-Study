#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
int pop[11];
vector<int> list[11];
int population;
int box[11];
int cur;
int ans = 987654321;

bool bfs()	//두 구역으로 나누어지는 지 체크
{
	int visited[11] = { 0 };
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (box[i] == 1) {
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {	//첫번째 구역
		int cur = q.front();
		q.pop();

		if (box[cur] == 0) continue;
		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (auto next : list[cur]) {
			if (visited[next] != 1) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] != box[i]) return false;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			q.push(i);
			break;
		}
	}

	while (!q.empty()) {	//두번째 구역
		int cur = q.front();
		q.pop();

		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (auto next : list[cur]) {
			if (visited[next] != 1) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) return false;
	}

	return true;
}

void dfs(int level, int limit, int n)
{
	if (level == limit) {
		int temp = population - cur;
		int diff = abs(temp - cur);	//두 구역의 인구 차이
		if (bfs()) {	//두 구역으로 나누어 졌다면
			ans = min(diff, ans);
		}

		return;
	}

	for (int i = n; i <= N; i++) {	//조합 뽑기
		box[i] = 1;
		cur += pop[i];
		dfs(level + 1, limit, i + 1);
		box[i] = 0;
		cur -= pop[i];
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &pop[i]);
		population += pop[i];
	}

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);

		for (int j = 0; j < num; j++) {
			int to;
			scanf("%d", &to);
			list[i].push_back(to);
		}
	}

	for (int i = 1; i <= N / 2; i++) {
		dfs(0, i, 1);
	}

	if (ans == 987654321) {
		printf("%d", -1);
		return 0;
	}
	printf("%d", ans);
}
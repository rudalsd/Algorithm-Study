#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, K;
bool visited[200001];
int from[200001];

int main()
{
	scanf("%d %d", &N, &K);

	if (N > K) {	//N이 K보다 크다면 x-1로 밖에 이동할 수 없으므로
		printf("%d\n", N - K);
		for (int i = N; i >= K; i--) {
			printf("%d ", i);
		}
		return 0;
	}

	visited[N] = true;

	queue<int> q;

	q.push({ N });

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K) {
			vector<int> ans;	//이동 경로
			for (int i = K; i != N; i = from[i]) {
				ans.push_back(i);
			}
			printf("%d\n", ans.size());
			printf("%d ", N);
			for (int i = ans.size() - 1; i >= 0; i--) {
				printf("%d ", ans[i]);
			}
		}

		if (cur - 1 >= 0) {
			if (visited[cur - 1] != true) {
				visited[cur - 1] = true;
				from[cur - 1] = cur;	//어디로 부터 왔는지 이동한 위치에서 저장
				q.push(cur - 1);
			}
		}
		if (visited[cur + 1] != true && cur < K) {
			visited[cur + 1] = true;
			from[cur + 1] = cur;
			q.push(cur + 1);
		}
		if (cur <= K) {
			if (visited[cur * 2] != true) {
				visited[cur * 2] = true;
				from[cur * 2] = cur;
				q.push(cur * 2);
			}
		}
	}
}
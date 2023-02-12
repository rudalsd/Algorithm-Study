#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<pair<int, int>> list[101];
int ans[101];
int basic[101];
int in[101];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int X, Y, K;
		scanf("%d %d %d", &X, &Y, &K);
		list[X].push_back({ Y,K });
		basic[X] = 1;
		in[Y]++;
	}

	queue<int> q;
	q.push(N);
	ans[N] = 1;

	while (!q.empty()) {
		const int cur = q.front();
		q.pop();

		for (auto& next : list[cur]) {
			ans[next.first] += ans[cur] * next.second;
			in[next.first]--;
			if (in[next.first] == 0) {
				q.push(next.first);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (basic[i] != 1) {
			printf("%d %d\n", i, ans[i]);
		}
	}
}
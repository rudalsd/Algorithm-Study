#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int cnt[1001];
int ans[1001];
vector<int> list[1001];

int main()
{
	scanf("%d %d", &N, &M);
	queue<int> q;

	for (int i = 0; i < M; i++) {
		int A, B;
		scanf("%d %d", &A, &B);

		list[A].push_back(B);
		cnt[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}

	while (!q.empty()) {
		const int cur = q.front();
		q.pop();

		for (auto& next : list[cur]) {
			cnt[next]--;
			if (cnt[next] == 0) {
				q.push(next);
				ans[next] += ans[cur] + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", ans[i]);
	}
}
#include<iostream>
#include<queue>

using namespace std;

int N, K;
pair<int,int> visited[500001];

int main()
{
	scanf("%d %d", &N, &K);

	if (N == K) {
		printf("0");
		return 0;
	}

	queue<pair<int, int>> q;

	q.push({ N,0 });
	for (int i = 0; i <= 500000; i++) {
		visited[i].first = 987654321;
		visited[i].second = 987654321;
	}
	visited[N].first = 0;

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		if (cnt % 2 == 0) {
			if (visited[cur].first < cnt) continue;
			visited[cur].first = cnt;

			if (cur > 0) {
				if (visited[cur - 1].second > cnt + 1) {
					visited[cur - 1].second = cnt + 1;
					q.push({ cur - 1,cnt + 1 });
				}
			}
			if (cur < 500000) {
				if (visited[cur + 1].second > cnt + 1) {
					visited[cur + 1].second = cnt + 1;
					q.push({ cur + 1,cnt + 1 });
				}
			}
			if (cur <= 250000) {
				if (visited[cur * 2].second > cnt + 1) {
					visited[cur * 2].second = cnt + 1;
					q.push({ cur * 2,cnt + 1 });
				}
			}
		}
		else {
			if (visited[cur].second < cnt) continue;
			visited[cur].second = cnt;

			if (cur > 0) {
				if (visited[cur - 1].first > cnt + 1) {
					visited[cur - 1].first = cnt + 1;
					q.push({ cur - 1,cnt + 1 });
				}
			}
			if (cur < 500000) {
				if (visited[cur + 1].first > cnt + 1) {
					visited[cur + 1].first = cnt + 1;
					q.push({ cur + 1,cnt + 1 });
				}
			}
			if (cur <= 250000) {
				if (visited[cur * 2].first > cnt + 1) {
					visited[cur * 2].first = cnt + 1;
					q.push({ cur * 2,cnt + 1 });
				}
			}
		}

		
	}

	int cnt = 1;
	int Min = 987654321;
	K++;

	while (K <= 500000) {
		if (visited[K].first != 987654321) {
			if (cnt % 2 == visited[K].first % 2 && cnt >= visited[K].first) {
				Min = min(Min, cnt);
			}
		}
		if (visited[K].second != 987654321) {
			if (cnt % 2 == visited[K].second % 2 && cnt >= visited[K].second) {
				Min = min(Min, cnt);
			}
		}

		cnt++;
		K += cnt;
	}

	if (Min != 987654321) {
		printf("%d", Min);
	}
	else {
		printf("-1");
	}
}

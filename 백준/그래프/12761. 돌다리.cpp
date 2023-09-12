#include<iostream>
#include<queue>

using namespace std;

int A, B, N, M;
int visited[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> N >> M;

	queue<pair<int, int>>q;
	q.push({ N,0 });

	visited[N] = 1;

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		if (cur == M) {
			cout << cnt;
			return 0;
		}

		if (cur < M) {
			if (cur + 1 <= 100000 && visited[cur + 1] == 0) {
				visited[cur + 1] = 1;
				q.push({ cur + 1,cnt + 1 });
			}

			if (cur + A <= 100000 && visited[cur + A] == 0) {
				visited[cur + A] = 1;
				q.push({ cur + A,cnt + 1 });
			}

			if (cur + B <= 100000 && visited[cur + B] == 0) {
				visited[cur + B] = 1;
				q.push({ cur + B,cnt + 1 });
			}

			if (cur * A <= 100000 && visited[cur * A] == 0) {
				visited[cur * A] = 1;
				q.push({ cur * A,cnt + 1 });
			}

			if (cur * B <= 100000 && visited[cur * B] == 0) {
				visited[cur * B] = 1;
				q.push({ cur * B,cnt + 1 });
			}
		}

		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			visited[cur - 1] = 1;
			q.push({ cur - 1,cnt + 1 });
		}

		if (cur - A >= 0 && visited[cur - A] == 0) {
			visited[cur - A] = 1;
			q.push({ cur - A,cnt + 1 });
		}

		if (cur - B >= 0 && visited[cur - B] == 0) {
			visited[cur - B] = 1;
			q.push({ cur - B,cnt + 1 });
		}
	}
}
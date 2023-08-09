#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct node {
	int x, y, R;
};

int T, N;
node arr[3000];
int visited[3000];

void bfs(int num)
{
	queue<int> q;

	q.push(num);

	while (!q.empty()) {
		const int x = arr[q.front()].x;
		const int y = arr[q.front()].y;
		const int R = arr[q.front()].R;
		q.pop();

		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				const int xx = arr[i].x;
				const int yy = arr[i].y;
				const int RR = arr[i].R;

				if (sqrt(pow(x - xx, 2) + pow(y - yy, 2)) <= R + RR) {
					visited[i] = 1;
					q.push(i);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y, R;
			cin >> x >> y >> R;
			arr[i] = { x,y,R };
		}

		int ans = 0;
		fill(visited, visited + N, 0);

		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				bfs(i);
				ans++;
			}
		}

		cout << ans << '\n';
	}
}
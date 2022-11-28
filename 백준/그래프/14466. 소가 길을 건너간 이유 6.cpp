#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, K, R;
int road[205][205];
int arr[101][101];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
vector<pair<int, int>> cow;

int bfs(int num)
{
	int ret = 0;
	int visited[101][101] = { 0 };
	queue<pair<int, int>> q;
	q.push({ cow[num].first, cow[num].second });

	while (!q.empty()) {
		const int r = q.front().first;
		const int c = q.front().second;
		q.pop();

		if (visited[r][c] == 1) continue;
		visited[r][c] = 1;

		if (arr[r][c] == 1) {
			ret++;
		}

		for (int i = 0; i < 4; i++) {
			const int rr = r + dr[i];
			const int cc = c + dc[i];

			if (rr > 0 && rr <= N && cc > 0 && cc <= N) {
				if (road[r + rr][c + cc] != 1) {
					q.push({ rr,cc });
				}
			}
		}
	}

	return ret - 1;
}

int main()
{
	scanf("%d %d %d", &N, &K, &R);

	for (int i = 0; i < R; i++) {
		int r, c, rr, cc;
		scanf("%d %d %d %d", &r, &c, &rr, &cc);

		road[r + rr][c + cc] = 1;	//길의 위치
	}

	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);

		arr[r][c] = 1;
		cow.emplace_back(r, c);
	}

	int pair = (K) * (K - 1) / 2;	//나올 수 있는 모든 쌍

	int ans = 0;	//길 없이 만날 수 있는 모든 쌍의 수

	for (int i = 0; i < cow.size(); i++) {
		ans += bfs(i);
	}

	printf("%d", pair - ans / 2);
}
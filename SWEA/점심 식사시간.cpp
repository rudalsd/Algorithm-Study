#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct step {
	int y;
	int x;
	int cost;
};

struct people {
	int y;
	int x;
	int step;
	int dist;
};

int N;
int arr[10][10];
step st[2];
vector<people> peo;
int cnt;
int m;

bool cmp(people left, people right)
{
	return left.dist > right.dist;
}

int minute()
{
	int min = 0;
	priority_queue<int, vector<int>, greater<>> pq[2];
	vector<people> sub = peo;
	while (!pq[0].empty() || !pq[1].empty() || !sub.empty())
	{
		min++;

		for (int i = 0; i < 3; i++) {
			if (!pq[0].empty()) {
				if (pq[0].top() == min) {
					pq[0].pop();
				}
			}
			if (!pq[1].empty()) {
				if (pq[1].top() == min) {
					pq[1].pop();
				}
			}
		}

		for (int i = sub.size() - 1; i >= 0; i--) {
			if (sub[i].dist <= min && pq[sub[i].step].size() < 3) {
				pq[sub[i].step].push(min + st[sub[i].step].cost);
				sub.erase(sub.begin() + i);
			}
		}
	}

	return min;
}

void dfs(int level)
{
	if (level == peo.size()) {
		int min = minute();
		if (m > min) {
			m = min;
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		peo[level].step = i;
		peo[level].dist = abs(st[i].y - peo[level].y) + abs(st[i].x - peo[level].x) + 1;
		dfs(level + 1);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		int now = 0;
		cnt = 0;
		m = 999;
		peo.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];

				if (arr[i][j] > 1) {
					st[now++] = { i,j,arr[i][j] };
				}

				if (arr[i][j] == 1) {
					peo.push_back({ i,j });
				}
			}
		}

		dfs(0);

		cout << "#" << t << " " << m << endl;
	}
}
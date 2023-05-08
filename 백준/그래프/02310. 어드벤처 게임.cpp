#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
char room[1001];
int charge[1001];
vector<int> list[1001];
int visited[1001][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list[0].push_back(1);

	while (1) {
		cin >> n;
		if (n == 0) return 0;

		for (int i = 1; i <= n; i++) {
			list[i].clear();
			fill(visited[i], visited[i] + 501, 0);
			cin >> room[i] >> charge[i];
			int next;
			while (1) {
				cin >> next;
				if (next == 0) break;
				list[i].push_back(next);
			}
		}

		queue<pair<int, int>> q;

		q.push({ 0, 0 });

		bool flag = false;

		while (!q.empty()) {
			const int cur = q.front().first;
			const int cost = q.front().second;
			q.pop();

			if (cur == n) {
				cout << "Yes\n";
				flag = true;
				break;
			}

			for (int& next : list[cur]) {
				if (room[next] == 'T') {
					if (cost >= charge[next]) {
						if (visited[next][cost] != 1) {
							visited[next][cost] = 1;
							q.push({ next,cost - charge[next] });
						}
					}
				}
				else if (room[next] == 'L') {
					if (cost < charge[next]) {
						if (visited[next][charge[next]] != 1) {
							visited[next][charge[next]] = 1;
							q.push({ next,charge[next] });
						}
					}
					else {
						if (visited[next][cost] != 1) {
							visited[next][cost] = 1;
							q.push({ next,cost });
						}
					}
				}
				else {
					if (visited[next][cost] != 1) {
						visited[next][cost] = 1;
						q.push({ next,cost });
					}
				}
			}
		}

		if (flag == false) {
			cout << "No\n";
		}
	}
}
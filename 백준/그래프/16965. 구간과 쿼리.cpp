#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;
vector<pair<int, int>> list;

bool bfs(int a, int b)
{
	int visited[101] = { 0 };

	queue<int>q;

	q.push(a - 1);
	visited[a - 1] = 1;

	while (!q.empty()) {
		const int cur = q.front();
		const int x = list[cur].first;
		const int y = list[cur].second;
		q.pop();

		if (cur == b - 1) {
			return true;
		}

		for (int i = 0; i < list.size();i++) {
			if (visited[i] != 1 && ((list[i].first < x && x < list[i].second) || (list[i].first < y && y < list[i].second))) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int x, y;
			cin >> x >> y;
			list.push_back({ x,y });
		}
		else {
			int a, b;
			cin >> a >> b;

			if (bfs(a, b)) cout << 1;
			else cout << 0;
			cout << '\n';
		}
	}
}
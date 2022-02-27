#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class chon {
public:
	int cnt;
	int num;
	chon(int a, int b)
	{
		cnt = a;
		num = b;
	}
};

int main()
{
	int n, m, rx, ry, x, y;
	vector<vector<chon>> list;
	vector<int> visited;
	queue<chon> queue;
	int cnt = 0;
	int flag = 0;

	cin >> n >> rx >> ry >> m;

	list.resize(n + 1);
	visited.resize(n + 1);
	chon a(0, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a = { 0, x };
		list[y].push_back(a);
		a = { 0, y };
		list[x].push_back(a);
	}

	a = { 0, ry };
	queue.push(a);

	while (!queue.empty())
	{
		int cur = queue.front().num;
		cnt = queue.front().cnt;
		queue.pop();
		if (cur == rx) {
			flag = 1;
			break;
		}

		if (visited[cur] == 1) continue;

		visited[cur] = 1;

		for (int i = 0; i < list[cur].size(); i++)
		{
			chon b(cnt + 1, list[cur][i].num);
			queue.push(b);
		}
	}

	if (flag == 1)
		cout << cnt;
	else
		cout << -1;
}
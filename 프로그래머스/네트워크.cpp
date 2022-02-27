#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> queue;
	vector<int>visited;
	vector<vector<int>> computers = {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1}
	};
	int n = 3;
	visited.resize(n);
	int cnt = 0;
	int flag = 1;
	queue.push(0);
	while (flag != 0)
	{
		cnt++;
		flag = 0;
		while (!queue.empty())
		{
			int cur = queue.front();
			queue.pop();
			if (visited[cur] == 1) continue;
			visited[cur] = 1;

			for (int i = 0; i < n; i++)
			{
				if (computers[cur][i] == 1)
					queue.push(i);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (visited[i] != 1)
			{
				flag = 1;
				queue.push(i);
				break;
			}
		}
	}

	cout << cnt;
}
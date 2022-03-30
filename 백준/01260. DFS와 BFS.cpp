#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> list;
vector<int> visited;

void run(int cur)
{
	visited[cur] = 1;
	cout << cur << " ";

	for (int i = 0; i < list[cur].size(); i++)
	{
		int next = list[cur][i];
		if (visited[next] != 1)
			run(next);
	}
}

int main()
{
	stack<int> stack;
	queue<int> queue;

	int N, M, V;

	cin >> N >> M >> V;

	list.resize(N + 1);
	visited.resize(N + 1);
	stack.push(V);

	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		list[node1].push_back(node2);
		list[node2].push_back(node1);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(list[i].begin(), list[i].end());
	}

	/*while (!stack.empty())
	{
		int cur = stack.top();
		stack.pop();
		if (visited[cur] == 1) continue;
		visited[cur] = 1;
		cout << cur<<" ";
		int len = list[cur].size();
		for (int i = len-1; i >=0; i--)
		{
			int next = list[cur][i];
			stack.push(next);
		}
	}*/

	run(V);


	cout << endl;

	for (int i = 1; i < N + 1; i++)
		visited[i] = 0;

	queue.push(V);

	while (!queue.empty())
	{
		int cur = queue.front();
		queue.pop();
		if (visited[cur] == 1) continue;
		visited[cur] = 1;
		cout << cur << " ";
		int len = list[cur].size();
		for (int i = 0; i < len; i++)
		{
			int next = list[cur][i];
			queue.push(next);
		}
	}
}
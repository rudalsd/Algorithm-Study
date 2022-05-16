#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>list;
vector<int>visited;
int cnt = 0;

void run(int cur)
{
	visited[cur] = 1;
	if (cur != 1)
		cnt++;

	int len = list[cur].size();
	for (int i = 0; i < len; i++)
	{
		int next = list[cur][i];
		if (visited[next] != 1)
			run(next);
	}
}

int main()
{
	int N, M, V;
	V = 1;
	cin >> N >> M;

	list.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		list[node1].push_back(node2);
		list[node2].push_back(node1);
	}

	run(V);

	cout << cnt;
}
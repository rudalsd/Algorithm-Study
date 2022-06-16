#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Node {
	int to;
	int dist;
};

int n;

vector<Node> list[10001];
int visited[10001];
int snode;
int diameter;

void dfs(int num, int dist)
{
	if (visited[num] == 1) {
		return;
	}

	if (diameter < dist) {
		diameter = dist;
		snode = num;
	}

	visited[num] = 1;

	for (int i = 0; i < list[num].size(); i++) {
		int next = list[num][i].to;
		int nextDist = list[num][i].dist;
		dfs(next, dist + nextDist);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int p, c, d;
		scanf("%d %d %d", &p, &c, &d);
		list[p].push_back({ c,d });
		list[c].push_back({ p,d });
	}

	dfs(1, 0);		//�� ��忡�� ���� �� ��带 ã��

	memset(visited, 0, sizeof(visited));

	dfs(snode, 0);	//������ ã�� ��忡�� ���� �� ��带 ã��

	cout << diameter;
}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct node {
	int to;
	int dist;
};

int V;
vector<node> list[100001];
int visited[100001];
int startNode;
int ans;

void dfs(int num, int dist)			//���������κ��� ���� �� ���� �Ÿ��� ����
{
	if (visited[num] == 1) {
		return;
	}
	visited[num] = 1;

	if (ans < dist) {
		ans = dist;
		startNode = num;
	}

	for (int i = 0; i < list[num].size(); i++) {
		int next = list[num][i].to;
		int nextDist = list[num][i].dist;
		dfs(next, dist + nextDist);
	}
}

int main()
{
	cin >> V;

	for (int i = 0; i < V; i++) {
		int n;
		cin >> n;
		while (1) {
			int to;
			scanf("%d", &to);
			if (to != -1) {
				int dist;
				scanf("%d", &dist);
				list[n].push_back({ to,dist });
			}
			else {
				break;
			}
		}
	}

	dfs(1, 0);		//1�� ��忡�� ���� �� ��� ����
	memset(visited, 0, sizeof(visited));
	dfs(startNode, 0);	//���� ������ ���� �� ���� �Ÿ� ����

	cout << ans;
}
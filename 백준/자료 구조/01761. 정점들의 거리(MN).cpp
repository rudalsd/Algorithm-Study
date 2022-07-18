#include<iostream>		//768ms
#include<vector>
#include<queue>

using namespace std;

struct node {
	int to;
	int dist;
};

struct tree {
	int parent;
	int depth;
	int dist;
};

int N, M;
vector<node> list[40001];		//����� ��� ����
int visited[40001];
tree arr[40001];			//�θ� ���, ����, �Ÿ��� ������ �迭

int main()
{
	cin >> N;

	arr[1] = { 0, 1, 0 };

	for (int i = 0; i < N - 1; i++) {		//����� ��� ����
		int a, b, dist;
		scanf("%d %d %d", &a, &b, &dist);
		list[a].push_back({ b,dist });
		list[b].push_back({ a,dist });
	}

	queue<node> q;
	q.push({ 1, 0 });

	while (!q.empty())		//1�� ����� ���̸� 1�� �ΰ� ���������� ���� +1
	{
		int to = q.front().to;
		q.pop();

		if (visited[to] == 1) continue;
		visited[to] = 1;

		for (int i = 0; i < list[to].size(); i++) {
			int next = list[to][i].to;
			int dist = list[to][i].dist;
			if (visited[next] != 1) {
				arr[next] = { to, arr[to].depth + 1, dist };
				q.push({ next, 0 });
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		int ans = 0;
		scanf("%d %d", &a, &b);
		if (arr[a].depth < arr[b].depth) {			//���̰� �ٸ��ٸ� ���� �����ֱ�
			while (arr[a].depth != arr[b].depth) {
				ans += arr[b].dist;
				b = arr[b].parent;
			}
		}
		else if (arr[a].depth > arr[b].depth) {
			while (arr[a].depth != arr[b].depth) {
				ans += arr[a].dist;
				a = arr[a].parent;
			}
		}
		//���̰� ���ٸ�
		while (1) {		//�θ� ������ ������ �ö󰡱�
			if (a == b) {
				break;
			}
			ans += arr[a].dist + arr[b].dist;
			a = arr[a].parent;
			b = arr[b].parent;
		}

		printf("%d\n", ans);
	}
}
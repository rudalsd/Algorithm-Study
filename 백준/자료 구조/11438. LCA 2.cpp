#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<int> list[100001];	//���� ����
int parent[100001][18];		//2^i��° �θ�
int height[100001];			//�� ����� ����
int visited[100001];		//�湮 ����
int limit;

void dfs(int cur)		//�׷���
{
	if (visited[cur] == 1) return;
	visited[cur] = 1;

	for (auto next : list[cur]) {
		if (visited[next] == 0) {
			height[next] = height[cur] + 1;
			parent[next][0] = cur;
			dfs(next);
		}
	}
}

int find(int a, int b)		//LCA ã��
{
	if (height[a] > height[b]) {	//a�� ��Ʈ�� �� ������
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = limit; i >= 0; i--) {	//���� ���߱�
		int mask = 1 << i;
		if (height[b] - height[a] >= mask) {
			b = parent[b][i];
		}
	}

	if (a == b) return a;	//���� ����� a return

	for (int i = limit; i >= 0; i--) {		//���� �θ� ã��
		if (parent[a][i] == parent[b][i]) continue;

		a = parent[a][i];
		b = parent[b][i];
	}

	return parent[a][0];
}

int main()
{
	scanf("%d", &N);

	limit = ceil(log2(N));

	for (int i = 0; i < N - 1; i++) {	//���� ���� ���
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	dfs(1);

	for (int i = 1; i < limit; i++) {	//parent�迭 ä���
		for (int j = 1; j <= N; j++) {
			int next = parent[j][i - 1];
			if (next != 0) {
				parent[j][i] = parent[next][i - 1];
			}
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", find(a, b));
	}
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<int>list[1001];											//�� ��忡 ����� ��� ���
int visited[1001];												//�湮 ���� üũ �迭

void bfs(int num)												//����� ���� visited ó��
{
	queue<int> q;
	q.push(num);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (int i = 0; i < list[cur].size(); i++) {
			q.push(list[cur][i]);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		list[start].push_back(end);
		list[end].push_back(start);
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {									//visited ó�� ���� ���� ��常 bfs ������
			cnt++;
			bfs(i);
		}
	}

	cout << cnt;
}
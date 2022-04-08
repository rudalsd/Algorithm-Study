#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> list[110];

struct Node {
	int num;
	int cnt;
};

int bfs(int num)												//bfs�� ���� �� �������� �Ÿ����� ��� ���� return
{
	int cnt = 0;

	int visited[110] = { 0 };
	queue<Node> q;
	q.push({ num,0 });

	while (!q.empty())
	{
		int curNum = q.front().num;
		int curCnt = q.front().cnt;
		q.pop();

		if (visited[curNum] == 1) continue;
		visited[curNum] = 1;
		cnt += curCnt;

		for (int i = 0; i < list[curNum].size(); i++) {
			q.push({ list[curNum][i], curCnt + 1 });
		}
	}

	return cnt;
}

int main()
{
	int Min = 987654321;
	int result = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {								//list�� �������� ������ ����
		int start, end;
		cin >> start >> end;

		list[start].push_back(end);
		list[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) {								//Node���� �ѹ��� bfs�� ������ �ּڰ��� ����
		int cnt = bfs(i);
		if (Min > cnt) {
			Min = cnt;
			result = i;											//result�� �ּڰ��� ������ Node�� ����
		}
	}

	cout << result;
}
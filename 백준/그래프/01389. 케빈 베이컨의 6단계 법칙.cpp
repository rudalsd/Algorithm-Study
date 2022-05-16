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

int bfs(int num)												//bfs를 돌려 각 노드까지의 거리들을 모두 더해 return
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

	for (int i = 0; i < M; i++) {								//list에 간선들의 정보를 저장
		int start, end;
		cin >> start >> end;

		list[start].push_back(end);
		list[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) {								//Node별로 한번씩 bfs를 돌려서 최솟값을 저장
		int cnt = bfs(i);
		if (Min > cnt) {
			Min = cnt;
			result = i;											//result의 최솟값을 가지는 Node를 저장
		}
	}

	cout << result;
}
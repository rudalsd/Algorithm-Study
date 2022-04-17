#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<int>list[1001];											//각 노드에 연결된 노드 기록
int visited[1001];												//방문 여부 체크 배열

void bfs(int num)												//연결된 노드들 visited 처리
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
		if (visited[i] != 1) {									//visited 처리 되지 않은 노드만 bfs 돌리기
			cnt++;
			bfs(i);
		}
	}

	cout << cnt;
}
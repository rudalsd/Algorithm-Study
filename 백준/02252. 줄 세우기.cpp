#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> list[32010];										//더 큰 학생 노드를 저장할 vector list
int in[32010];													//들어오는 간선의 개수를 저장할 배열

int main()
{
	cin >> N >> M;

	queue<int> q;

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		in[b]++;												//들어오는 간선 ++
		list[a].push_back(b);									//더 큰 학생 노드들을 저장
	}

	for (int i = 1; i <= N; i++) {								//N번 돌면서
		if (in[i] == 0) {										//들어오는 간선의 개수가 0인 노드를 q에 넣기
			q.push(i);
		}
	}

	while (!q.empty())											//q가 빌 때까지
	{
		int num = q.front();
		q.pop();
		cout << num << " ";										//노드 출력

		for (int i = 0; i < list[num].size(); i++) {
			in[list[num][i]]--;									//연결된 노드의 들어오는 간선 --
			if (in[list[num][i]] == 0) {						//들어오는 간선의 개수가 0일 때
				q.push(list[num][i]);							//q에 집어넣기
			}
		}
	}
}
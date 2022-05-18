#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int edge[1001];												//들어오는 간선의 개수를 저장할 배열
vector<int> list[1001];										//다음 노드를 기록할 vector
vector<int> seq;											//순서를 저장할 vector

int main()
{
	cin >> N >> M;
	queue<int> q;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		int before = 0;
		for (int j = 0; j < num; j++) {
			int a;
			scanf("%d", &a);
			if (before != 0) {
				edge[a]++;									//만약 이전 노드가 있다면 edge++
				list[before].push_back(a);					//이전 노드에 지금 노드를 push
			}
			before = a;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (edge[i] == 0) {									//들어오는 간선이 없을 때 q에 push
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		seq.push_back(cur);									//순서에 cur을 push

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];
			edge[next]--;									//다음 노드의 들어오는 간선--
			if (edge[next] == 0) {							//다음 노드의 들어오는 간선이 0이라면
				q.push(next);								//q에 push
			}
		}
	}

	if (seq.size() == N) {									//모든 노드가 순서대로 공연이 가능하다면
		for (int i = 0; i < seq.size(); i++) {				//순서대로 출력
			printf("%d\n", seq[i]);
		}
	}
	else {													//아니라면 0출력
		printf("0");
	}
}
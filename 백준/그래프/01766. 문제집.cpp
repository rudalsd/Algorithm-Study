#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> list[32001];												//선행 노드의 번호들을 기록할 벡터
int edge[32001];														//선행 노드의 개수를 저장할 배열

int main()
{
	cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> pq;					//문제 번호가 빠를수록 먼저 나오도록 설정
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		edge[B]++;														//선행 노드가 있으면 edge++
		list[A].push_back(B);											//선행 노드의 번호를 push
	}

	for (int i = 1; i <= N; i++) {
		if (edge[i] == 0) {
			pq.push(i);													//선행 노드가 없으면 pq에 push
		}
	}

	while (!pq.empty())
	{
		int cur = pq.top();												//현재 문제 번호
		pq.pop();

		cout << cur << " ";												//현재 문제 번호 출력

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];
			edge[next]--;												//후행 노드의 간선 -1
			if (edge[next] == 0) {										//후행 노드의 간선이 0이면
				pq.push(next);											//pa에 push
			}
		}
	}
}
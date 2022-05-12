#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> list[32010];										//더 큰 학생 노드를 저장할 vector list
int in[32010];													//들어오는 간선의 개수를 저장할 배열
int visited[32010];												//방문한 노드를 체크할 배열

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

	for (int k = 0; k < N; k++) {								//총 N번 반복
		for (int i = 1; i <= N; i++) {							//N번 돌면서
			if (visited[i] == 1) continue;						//방문했으면 continue
			if (in[i] == 0) {									//들어오는 간선이 0개이면
				visited[i] = 1;									//방문 체크 후
				cout << i << " ";								//출력
				for (int j = 0; j < list[i].size(); j++) {
					in[list[i][j]]--;							//간선--
				}
			}
		}
	}
}
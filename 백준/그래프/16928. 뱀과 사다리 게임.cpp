#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[101];		//각 칸의 이동 위치
int visited[101];	//각 칸의 방문 여부

struct node {
	int cur;
	int cnt;
};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= 100; i++) {	//각 칸의 이동 위치를 자신으로 초기화
		arr[i] = i;
	}

	for (int i = 0; i < N; i++) {	//사다리 입력
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a] = b;
	}

	for (int i = 0; i < M; i++) {	//뱀 입력
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a] = b;
	}

	queue<node> q;
	q.push({ 1, 0 });

	while (1)
	{
		int cur = q.front().cur;
		int cnt = q.front().cnt;
		q.pop();

		if (cur == 100) {	//100번 칸에 도착하면 cnt 출력 후 종료
			printf("%d", cnt);
			return 0;
		}

		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (int i = 1; i <= 6; i++) {
			int next = arr[cur + i];	//이동할 칸
			if (visited[next] != 1) {
				q.push({ next, cnt + 1 });
			}
		}
	}
}
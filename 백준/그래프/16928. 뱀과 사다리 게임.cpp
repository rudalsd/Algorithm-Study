#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[101];		//�� ĭ�� �̵� ��ġ
int visited[101];	//�� ĭ�� �湮 ����

struct node {
	int cur;
	int cnt;
};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= 100; i++) {	//�� ĭ�� �̵� ��ġ�� �ڽ����� �ʱ�ȭ
		arr[i] = i;
	}

	for (int i = 0; i < N; i++) {	//��ٸ� �Է�
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a] = b;
	}

	for (int i = 0; i < M; i++) {	//�� �Է�
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

		if (cur == 100) {	//100�� ĭ�� �����ϸ� cnt ��� �� ����
			printf("%d", cnt);
			return 0;
		}

		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (int i = 1; i <= 6; i++) {
			int next = arr[cur + i];	//�̵��� ĭ
			if (visited[next] != 1) {
				q.push({ next, cnt + 1 });
			}
		}
	}
}
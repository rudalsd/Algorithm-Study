#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int edge[1001];												//������ ������ ������ ������ �迭
vector<int> list[1001];										//���� ��带 ����� vector
vector<int> seq;											//������ ������ vector

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
				edge[a]++;									//���� ���� ��尡 �ִٸ� edge++
				list[before].push_back(a);					//���� ��忡 ���� ��带 push
			}
			before = a;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (edge[i] == 0) {									//������ ������ ���� �� q�� push
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		seq.push_back(cur);									//������ cur�� push

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];
			edge[next]--;									//���� ����� ������ ����--
			if (edge[next] == 0) {							//���� ����� ������ ������ 0�̶��
				q.push(next);								//q�� push
			}
		}
	}

	if (seq.size() == N) {									//��� ��尡 ������� ������ �����ϴٸ�
		for (int i = 0; i < seq.size(); i++) {				//������� ���
			printf("%d\n", seq[i]);
		}
	}
	else {													//�ƴ϶�� 0���
		printf("0");
	}
}
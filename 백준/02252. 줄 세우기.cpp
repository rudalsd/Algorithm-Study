#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> list[32010];										//�� ū �л� ��带 ������ vector list
int in[32010];													//������ ������ ������ ������ �迭
int visited[32010];												//�湮�� ��带 üũ�� �迭

int main()
{
	cin >> N >> M;

	queue<int> q;

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		in[b]++;												//������ ���� ++
		list[a].push_back(b);									//�� ū �л� ������ ����
	}

	for (int k = 0; k < N; k++) {								//�� N�� �ݺ�
		for (int i = 1; i <= N; i++) {							//N�� ���鼭
			if (visited[i] == 1) continue;						//�湮������ continue
			if (in[i] == 0) {									//������ ������ 0���̸�
				visited[i] = 1;									//�湮 üũ ��
				cout << i << " ";								//���
				for (int j = 0; j < list[i].size(); j++) {
					in[list[i][j]]--;							//����--
				}
			}
		}
	}
}
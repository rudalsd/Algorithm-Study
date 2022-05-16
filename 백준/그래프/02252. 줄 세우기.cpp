#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> list[32010];										//�� ū �л� ��带 ������ vector list
int in[32010];													//������ ������ ������ ������ �迭

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

	for (int i = 1; i <= N; i++) {								//N�� ���鼭
		if (in[i] == 0) {										//������ ������ ������ 0�� ��带 q�� �ֱ�
			q.push(i);
		}
	}

	while (!q.empty())											//q�� �� ������
	{
		int num = q.front();
		q.pop();
		cout << num << " ";										//��� ���

		for (int i = 0; i < list[num].size(); i++) {
			in[list[num][i]]--;									//����� ����� ������ ���� --
			if (in[list[num][i]] == 0) {						//������ ������ ������ 0�� ��
				q.push(list[num][i]);							//q�� ����ֱ�
			}
		}
	}
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> list[32001];												//���� ����� ��ȣ���� ����� ����
int edge[32001];														//���� ����� ������ ������ �迭

int main()
{
	cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> pq;					//���� ��ȣ�� �������� ���� �������� ����
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		edge[B]++;														//���� ��尡 ������ edge++
		list[A].push_back(B);											//���� ����� ��ȣ�� push
	}

	for (int i = 1; i <= N; i++) {
		if (edge[i] == 0) {
			pq.push(i);													//���� ��尡 ������ pq�� push
		}
	}

	while (!pq.empty())
	{
		int cur = pq.top();												//���� ���� ��ȣ
		pq.pop();

		cout << cur << " ";												//���� ���� ��ȣ ���

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i];
			edge[next]--;												//���� ����� ���� -1
			if (edge[next] == 0) {										//���� ����� ������ 0�̸�
				pq.push(next);											//pa�� push
			}
		}
	}
}
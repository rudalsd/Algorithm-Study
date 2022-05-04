#include<iostream>
#include<queue>

using namespace std;

int N;

struct room {
	int time;
	int cur;
};

struct cmp {													//priority queue cmp����ü ����
	bool operator()(room right, room left) {
		if (left.time < right.time) return true;				//���� �ð��� ���� ������ ����
		if (left.time > right.time) return false;
		return left.cur < right.cur;							//������ �ð��� ���� ������ ����
	}
};

int main()
{
	cin >> N;

	priority_queue<room, vector<room>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int  start, end;
		scanf("%d %d", &start, &end);
		pq.push({ start,1 });									//�����ϴ� �ð��� ���¿� 1 �ֱ�
		pq.push({ end,0 });										//������ �ð��� ���¿� 0 �ֱ�
	}

	int cnt = 0;
	int max = 0;

	while (!pq.empty())
	{
		int time = pq.top().time;
		int cur = pq.top().cur;
		pq.pop();

		if (cur == 1) {											//ȸ�ǰ� ���������� cnt++
			cnt++;
		}
		else {													//ȸ�ǰ� �������� cnt--
			cnt--;
		}

		if (max < cnt) {										//�ʿ��� ȸ�ǽ��� �ִ��� max�� ����
			max = cnt;
		}
	}

	cout << max;
}
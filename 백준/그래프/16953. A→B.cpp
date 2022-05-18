#include <iostream>
#include <queue>

using namespace std;

long long A, B;

struct Node {
	long long num;
	int cnt;
};

int main()
{
	cin >> A >> B;

	queue<Node> q;

	q.push({ A,1 });

	while (!q.empty()) {
		long long num = q.front().num;
		int cnt = q.front().cnt;
		q.pop();

		if (num > B) continue;									//num�� B���� ũ�� continue

		if (num == B) {											//num�� B�� ���ٸ� cnt�� ����ϰ� return
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			long long next = 0;
			if (i == 0) {
				next = num * 2;									//���� ���ڿ� 2�� ���� ���� next�� �ֱ�
			}
			else {
				next = num * 10 + 1;							//���� ���ڿ� 10�� ���ϰ� 1�� ���� ���� next�� �ֱ�
			}
			q.push({ next, cnt + 1 });							//q�� next�� cnt+1�� �ֱ�
		}
	}

	cout << -1;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C;																//������ �뷮
int visited[205][205][205];													//���� ���¸� ���� visited�迭
vector<int> box;															//A���� ������� �� C���� ���� ���� ������ vector

struct water {
	int A;
	int B;
	int C;
};

int main()
{
	cin >> A >> B >> C;

	queue<water> q;
	q.push({ 0,0,C });

	while (!q.empty()) {
		int curA = q.front().A;
		int curB = q.front().B;
		int curC = q.front().C;

		q.pop();

		if (visited[curA][curB][curC] == 1) continue;						//����� ���� ��Ȳ�� �־��ٸ� continue;
		visited[curA][curB][curC] = 1;

		if (curA == 0) {													//A���� ����ִٸ� box�� ���� C���� ����
			box.push_back(curC);
		}

		if (curA + curB <= B) {												//A���� B
			q.push({ 0, curA + curB, curC });
		}
		else {
			q.push({ curA - (B - curB), B, curC });
		}
		if (curA + curC <= C) {												//A���� C
			q.push({ 0,curB, curC + curA });
		}
		else {
			q.push({ curA - (C - curC), curB, C });
		}
		if (curB + curA <= A) {												//B���� A
			q.push({ curA + curB, 0, curC });
		}
		else {
			q.push({ A, curB - (A - curA), curC });
		}
		if (curB + curC <= C) {												//B���� C
			q.push({ curA,0, curC + curB });
		}
		else {
			q.push({ curA, curB - (C - curC), C });
		}
		if (curC + curA <= A) {												//C���� A
			q.push({ curA + curC, curB, 0 });
		}
		else {
			q.push({ A, curB, curC - (A - curA) });
		}
		if (curB + curC <= B) {												//C���� B
			q.push({ curA,curC + curB, 0 });
		}
		else {
			q.push({ curA, B, curC - (B - curB) });
		}
	}

	sort(box.begin(), box.end());											//�������� ����

	for (int i = 0; i < box.size(); i++) {
		cout << box[i] << " ";
	}
}
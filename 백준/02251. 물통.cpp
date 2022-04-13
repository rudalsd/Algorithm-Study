#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C;																//물통의 용량
int visited[205][205][205];													//물의 상태를 담을 visited배열
vector<int> box;															//A통이 비어있을 때 C통의 물의 양을 저장할 vector

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

		if (visited[curA][curB][curC] == 1) continue;						//현재와 같은 상황이 있었다면 continue;
		visited[curA][curB][curC] = 1;

		if (curA == 0) {													//A통이 비어있다면 box에 현재 C값을 저장
			box.push_back(curC);
		}

		if (curA + curB <= B) {												//A에서 B
			q.push({ 0, curA + curB, curC });
		}
		else {
			q.push({ curA - (B - curB), B, curC });
		}
		if (curA + curC <= C) {												//A에서 C
			q.push({ 0,curB, curC + curA });
		}
		else {
			q.push({ curA - (C - curC), curB, C });
		}
		if (curB + curA <= A) {												//B에서 A
			q.push({ curA + curB, 0, curC });
		}
		else {
			q.push({ A, curB - (A - curA), curC });
		}
		if (curB + curC <= C) {												//B에서 C
			q.push({ curA,0, curC + curB });
		}
		else {
			q.push({ curA, curB - (C - curC), C });
		}
		if (curC + curA <= A) {												//C에서 A
			q.push({ curA + curC, curB, 0 });
		}
		else {
			q.push({ A, curB, curC - (A - curA) });
		}
		if (curB + curC <= B) {												//C에서 B
			q.push({ curA,curC + curB, 0 });
		}
		else {
			q.push({ curA, B, curC - (B - curB) });
		}
	}

	sort(box.begin(), box.end());											//오름차순 정렬

	for (int i = 0; i < box.size(); i++) {
		cout << box[i] << " ";
	}
}
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

		if (num > B) continue;									//num이 B보다 크면 continue

		if (num == B) {											//num이 B와 같다면 cnt를 출력하고 return
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			long long next = 0;
			if (i == 0) {
				next = num * 2;									//지금 숫자에 2를 곱한 값을 next에 넣기
			}
			else {
				next = num * 10 + 1;							//지금 숫자에 10을 곱하고 1을 더한 값을 next에 넣기
			}
			q.push({ next, cnt + 1 });							//q에 next와 cnt+1을 넣기
		}
	}

	cout << -1;
}
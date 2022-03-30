#include<iostream>
#include<queue>

using namespace std;

struct Node {
	int num;
	int cnt;
};

int main()
{
	int N;
	cin >> N;

	queue<Node> q;
	q.push({ N,0 });

	while (!q.empty())
	{
		int num = q.front().num;
		int cnt = q.front().cnt;
		q.pop();

		if (num == 1) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (num % 2 == 0) {
					q.push({ num / 2,cnt + 1 });
				}
			}
			else if (i == 1) {
				if (num % 3 == 0) {
					q.push({ num / 3,cnt + 1 });
				}
			}
			else {
				q.push({ num - 1,cnt + 1 });
			}
		}
	}
}
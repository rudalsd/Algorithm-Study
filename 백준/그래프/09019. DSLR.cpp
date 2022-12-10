#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct node {
	int cur;
	string reg;
};

int left(int A)
{
	A *= 10;
	A += A / 10000;
	A %= 10000;

	return A;
}

int right(int A)
{
	int temp = A % 10;
	A /= 10;
	A += temp * 1000;

	return A;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int A, B;
		int visited[10000] = { 0 };

		scanf("%d %d", &A, &B);

		queue<node> q;
		string vect;

		q.push({ A,  vect });
		visited[A] = 1;

		while (!q.empty()) {
			int cur = q.front().cur;
			string str = q.front().reg;
			q.pop();

			if (cur == B) {
				for (auto next : str) {
					printf("%c", next);
				}
				printf("\n");
				break;
			}

			vector<char> temp;
			int l = left(cur);
			int r = right(cur);
			int d = (cur * 2) % 10000;
			int s = (cur + 9999) % 10000;
			if (visited[l] != 1) {
				visited[l] = 1;
				q.push({ l, str + 'L' });
			}
			if (visited[r] != 1) {
				visited[r] = 1;
				q.push({ r, str + 'R' });
			}
			if (visited[d] != 1) {
				visited[d] = 1;
				q.push({ d, str + 'D' });
			}
			if (visited[s] != 1) {
				visited[s] = 1;
				q.push({ s, str + 'S' });
			}
		}
	}
}
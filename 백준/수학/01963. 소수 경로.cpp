#include<iostream>
#include<queue>

using namespace std;

int T, A, B;
int check[10000];
int visited[10000];

int bfs(int A, int B)
{
	fill(visited, visited + 10000, 0);
	queue<pair<int, int>> q;

	q.push({ A,0 });
	visited[A] = 1;

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		if (cur == B) {
			return cnt;
		}

		int temp = cur % 1000;

		for (int i = 1; i <= 9; i++) {
			int next = temp + i * 1000;
			if (visited[next] != 1) {
				visited[next] = 1;
				if (check[next] == 0) {
					q.push({ next, cnt + 1 });
				}
			}
		}

		temp = cur;

		for (int i = 1; i <= 9; i++) {
			temp += 100;
			if ((temp % 1000) / 100 == 0) temp -= 1000;
			if (visited[temp] != 1) {
				visited[temp] = 1;
				if (check[temp] == 0) {
					q.push({ temp, cnt + 1 });
				}
			}
		}

		temp = cur;

		for (int i = 1; i <= 9; i++) {
			temp += 10;
			if ((temp % 100) / 10 == 0) temp -= 100;
			if (visited[temp] != 1) {
				visited[temp] = 1;
				if (check[temp] == 0) {
					q.push({ temp, cnt + 1 });
				}
			}
		}

		temp = cur;

		for (int i = 1; i <= 9; i++) {
			temp += 1;
			if (temp % 10 == 0) temp -= 10;
			if (visited[temp] != 1) {
				visited[temp] = 1;
				if (check[temp] == 0) {
					q.push({ temp, cnt + 1 });
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 2; i <= 5000; i++) {
		for (int j = 2; j <= 5000; j++) {
			if (i * j < 10000) {
				check[i * j] = 1;
			}
			else break;
		}
	}

	while (T--) {
		cin >> A >> B;

		int temp = bfs(A, B);

		if (temp != -1) {
			cout << temp << '\n';
		}
		else {
			cout << "Impossible\n";
		}
	}
}
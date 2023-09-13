#include<iostream>
#include<queue>

using namespace std;

int M, N;
char arr[1000][1001];
int visited[1000][1000];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		if (arr[0][i] == '0') {
			q.push({ 0,i });
			visited[0][i] = 1;
		}
	}

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < M && xx >= 0 && xx < N) {
				if (visited[yy][xx] == 0 && arr[yy][xx] == '0') {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
			}
			else if (yy == M) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
}
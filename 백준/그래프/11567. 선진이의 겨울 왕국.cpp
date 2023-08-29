#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n, m;
string arr[500];
int visited[500][500];
int r1, c1, r2, c2;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'X') {
				visited[i][j] = 1;
			}
		}
	}

	cin >> r1 >> c1 >> r2 >> c2;
	r1--; r2--; c1--; c2--;

	queue<pair<int, int>> q;

	q.push({ r1,c1 });
	visited[r1][c1] = 1;

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < n && xx >= 0 && xx < m) {
				if (visited[yy][xx] == 0) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
				else if (yy == r2 && xx == c2) {
					cout << "YES";
					return 0;
				}
			}
		}
	}

	cout << "NO";
}

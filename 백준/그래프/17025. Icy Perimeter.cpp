#include<iostream>
#include<queue>

using namespace std;

int N;
char arr[1001][1001];
int visited[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

pair<int,int> bfs(int y, int x)
{
	int ret = 1;
	int cnt = 0;

	queue<pair<int,int>> q;

	q.push({ y,x });

	visited[y][x] = 1;

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == '#') {
					ret++;
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
				else if(arr[yy][xx] == '.'){
					cnt++;
				}
			}
			else {
				cnt++;
			}
		}

	}

	return make_pair(ret,cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && arr[i][j] == '#') {
				pair<int, int> temp = bfs(i, j);

				if (ans < temp.first) {
					ans = temp.first;
					cnt = temp.second;
				}
				if (ans == temp.first) {
					cnt = min(cnt, temp.second);
				}
			}
		}
	}

	cout << ans << ' ' << cnt;
}
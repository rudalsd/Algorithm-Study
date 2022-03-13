#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[20][20];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int K;

struct pos {
	int y;
	int x;
	int cnt;
};

int Cnt(int y, int x, int n)
{
	int max = 0;
	queue<pos> q;
	q.push({ y,x,1 });
	int cnt = 0;
	int visited[20][20] = { 0 };
	visited[y][x] = 1;
	int price = n * n + (n - 1) * (n - 1);
	if (arr[y][x] == 1)cnt++;
	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		int curCnt = q.front().cnt;
		q.pop();

		if (curCnt == n) {
			if (cnt * M - price >= 0) {
				return cnt;
			}
			break;
		}

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					if (arr[yy][xx] == 1) {
						cnt++;
					}
					q.push({ yy,xx,curCnt + 1 });
				}
			}
		}
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					cnt++;
				}
			}
		}

		for (int i = N+1; i >= 1; i--)
		{
			if (cnt * M >= (i * i) + (i - 1) * (i - 1)) {
				K = i;
				break;
			}
		}

		int max = 0;
		for (int k = K; k >= 1; k--) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int cnt = Cnt(i, j, k);
					if (max < cnt) {
						max = cnt;
					}
				}
			}
			if (max != 0) {
				break;
			}
		}

		cout << "#" << t << " " << max << endl;
	}
}

#include <iostream>
#include <queue>

using namespace std;

int N, W, H;
int arr[15][12];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

class Node {
public:
	int y;
	int x;
	int cnt;
};

void after(int n)
{
	int idx = 0;
	for (int i = 0; i < H; i++) {
		if (arr[i][n] > 0) {
			idx = i;
			break;
		}
	}

	Node start = { idx, n, arr[idx][n] };
	queue<Node> q;
	q.push(start);

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		arr[cy][cx] = 0;

		if (cnt == 1 || cnt == 0) {
			continue;
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < cnt; j++) {
					int yy = cy + dy[i] * j;
					int xx = cx + dx[i] * j;
					if (yy >= 0 && yy < H && xx >= 0 && xx < W) {
						Node next = { yy,xx,arr[yy][xx] };
						q.push(next);
					}
				}
			}
		}
	}

	for (int i = 0; i < W; i++) {
		int cur = H - 1;
		for (int j = H - 1; j >= 0; j--) {
			if (arr[j][i] > 0) {
				arr[cur][i] = arr[j][i];
				if (cur != j)
					arr[j][i] = 0;
				cur--;
			}
		}
	}
}

int m;

void dfs(int level)
{
	if (level == N)
	{
		int cnt = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (arr[i][j] > 0)
					cnt++;
		if (cnt < m)
			m = cnt;
		return;
	}

	int before[15][12] = { 0 };

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			before[i][j] = arr[i][j];

	for (int i = 0; i < W; i++) {
		after(i);
		dfs(level + 1);
		for (int j = 0; j < H; j++)
			for (int k = 0; k < W; k++)
				arr[j][k] = before[j][k];
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		m = 99;
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> arr[i][j];

		dfs(0);

		cout << "#" << t << " " << m << endl;
	}
}
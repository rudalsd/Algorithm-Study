#include<iostream>
#include<vector>
#include<queue>

using namespace std;
char arr[1000][1001];
int visited[1000][1000][2];

class status {
public:
	int x;
	int y;
	int cur;
	int m;
	status(int a, int b, int c, int d)
	{
		y = a;
		x = b;
		cur = c;
		m = d;
	}
};

int main()
{
	int N, M, flag = 0;
	queue<status> queue;
	status start(0, 0, 0, 1);
	cin >> N >> M;
	int y, x, cur, m;
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	queue.push(start);
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };

	while (!queue.empty())
	{
		y = queue.front().y;
		x = queue.front().x;
		cur = queue.front().cur;
		m = queue.front().m;
		queue.pop();
		int yy, xx;
		if (y == N - 1 && x == M - 1)
		{
			flag = 1;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			yy = y + dy[i];
			xx = x + dx[i];
			status b(yy, xx, cur, m + 1);
			if (yy >= 0 && yy < N && xx >= 0 && xx < M)
			{
				if (visited[yy][xx][cur] != 1) {
					if (arr[yy][xx] == '0')
					{
						queue.push(b);
						visited[yy][xx][cur] = 1;
					}
					else if (arr[yy][xx] == '1' && cur == 0)
					{
						b.cur = 1;
						queue.push(b);
						visited[yy][xx][1] = 1;
					}
				}
			}
		}
	}
	if (flag == 1)
		cout << m;
	else
		cout << -1;
}
#include<iostream>
#include<queue>

using namespace std;

int R1, C1, R2, C2;
int visited[10][9];
int dy[8][3] = {
	-1,-1,-1,
	0,-1,-1,
	0,1,1,
	1,1,1,
	1,1,1,
	0,1,1,
	0,-1,-1,
	-1,-1,-1
};
int dx[8][3] = {
	0,1,1,
	1,1,1,
	1,1,1,
	0,1,1,
	0,-1,-1,
	-1,-1,-1,
	-1,-1,-1,
	0,-1,-1
};

struct node {
	int y;
	int x;
	int cnt;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R1 >> C1 >> R2 >> C2;

	queue<node> q;

	q.push({ R1,C1,0 });
	visited[R1][C1] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		q.pop();

		if (y == R2 && x == C2) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 8; i++) {
			int yy = y;
			int xx = x;
			bool flag = true;
			for (int j = 0; j < 3; j++) {
				yy += dy[i][j];
				xx += dx[i][j];
				if (yy == R2 && xx == C2 && j != 2) {
					flag = false;
				}
			}

			if (yy >= 0 && yy < 10 && xx >= 0 && xx < 9 && flag) {
				if (visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	cout << -1;
}

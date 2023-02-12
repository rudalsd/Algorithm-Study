#include<iostream>
#include<queue>

using namespace std;

int N, M;
char arr[51][51];
int Sy, Sx;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[32][51][51];

struct node {
	int y;
	int x;
	int cnt;
	int stf;
};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%s", &arr[i]);
	}

	int ea = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'S') {
				Sy = i;
				Sx = j;
			}
			else if (arr[i][j] == 'X') {
				arr[i][j] = '0' + ea;
				ea++;
			}
		}
	}

	queue<node> q;

	q.push({ Sy,Sx,0,0 });
	visited[0][Sy][Sx] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		const int stf = q.front().stf;
		q.pop();

		if (arr[y][x] == 'E') {
			if (stf == (1 << ea) - 1) {
				printf("%d", cnt);
			}
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < M && xx >= 0 && xx < N) {
				if (arr[yy][xx] >='0' && arr[yy][xx] <'5') {
					const int temp = stf | (1 << (arr[yy][xx] - '0'));
					if (visited[temp][yy][xx] != 1) {
						visited[temp][yy][xx] = 1;
						q.push({ yy,xx,cnt + 1,temp });
					}
				}
				else if (arr[yy][xx] != '#') {
					if (visited[stf][yy][xx] != 1) {
						visited[stf][yy][xx] = 1;
						q.push({ yy,xx,cnt + 1,stf });
					}
				}
			}
		}
	}
}
#include<iostream>
#include<queue>

using namespace std;

int N, M;
char arr[51][51];
int visited[130][50][50];
int Sy, Sx;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int key;
	int cnt;
};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') {
				arr[i][j] = '.';
				Sy = i;
				Sx = j;
			}
		}
	}

	queue<node> q;
	q.push({ Sy,Sx,0,0 });
	visited[0][Sy][Sx] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int key = q.front().key;
		const int cnt = q.front().cnt;
		q.pop();

		if (arr[y][x] == '1') {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '.' || arr[yy][xx] == '1') {
					if (visited[key][yy][xx] != 1) {
						visited[key][yy][xx] = 1;
						q.push({ yy,xx,key,cnt + 1 });
					}
				}
				else if (arr[yy][xx] >= 'a' && arr[yy][xx] <= 'f') {
					int newKey = key | (1 << arr[yy][xx] - 'a');
					if (visited[newKey][yy][xx] != 1) {
						visited[newKey][yy][xx] = 1;
						q.push({ yy,xx,newKey,cnt + 1 });
					}
				}
				else if (arr[yy][xx] >= 'A' && arr[yy][xx] <= 'F') {
					if (1 << (arr[yy][xx] - 'A') & key) {
						if (visited[key][yy][xx] != 1) {
							visited[key][yy][xx] = 1;
							q.push({ yy,xx,key,cnt + 1 });
						}
					}
				}
			}
		}
	}

	printf("-1");
}

#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0, 0, -1, 1 };

struct node {
	int y;
	int x;
	int cnt;
};

int main()
{
	scanf("%d %d", &M, &N);
	queue<node> q;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push({ i,j,0 });
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		ans = max(ans, cnt);

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == 0) {	//익지 않은 토마토가 있다면
					arr[yy][xx] = 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {		//안 익은 토마토가 하나라도 있으면
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", ans);
}
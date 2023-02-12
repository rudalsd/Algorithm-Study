#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[501][501];
int visited[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
};

void setArea(int X1, int Y1, int X2, int Y2, int num)
{
	if (X1 > X2) swap(X1, X2);
	if (Y1 > Y2) swap(Y1, Y2);

	for (int i = Y1; i <= Y2; i++) {
		for (int j = X1; j <= X2; j++) {
			arr[i][j] = num;
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int X1, Y1, X2, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		setArea(X1, Y1, X2, Y2, 1);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int X1, Y1, X2, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		setArea(X1, Y1, X2, Y2, 2);
	}

	deque<node> deq;

	deq.push_back({ 0,0,0 });
	visited[0][0] = 1;

	while (!deq.empty()) {
		const int y = deq.front().y;
		const int x = deq.front().x;
		const int cnt = deq.front().cnt;
		deq.pop_front();

		if (y == 500 && x == 500) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy <= 500 && xx >= 0 && xx <= 500) {
				if (visited[yy][xx] == 0 && arr[yy][xx] != 2) {
					visited[yy][xx] = 1;
					if (arr[yy][xx] == 0) {
						deq.push_front({ yy,xx,cnt });
					}
					else {
						deq.push_back({ yy,xx,cnt + 1 });
					}
				}
			}
		}
	}

	printf("-1");
}
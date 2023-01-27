#include<iostream>
#include<queue>

using namespace std;

int N, M;
char arr[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[100][100];

struct node {
	int y;
	int x;
	int cnt;
};

int main()
{
	deque<node> deq;
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	deq.push_back({ 0,0,0 });
	visited[0][0] = 1;

	while (!deq.empty()) {
		const int y = deq.front().y;
		const int x = deq.front().x;
		const int cnt = deq.front().cnt;
		deq.pop_front();

		if (y == N - 1 && x == M - 1) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					if (arr[yy][xx] == '0') {
						deq.push_front({ yy,xx,cnt });
					}
					else {
						deq.push_back({ yy,xx,cnt + 1 });
					}
				}
			}
		}
	}
}
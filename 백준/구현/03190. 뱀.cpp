#include<iostream>
#include<deque>

using namespace std;

struct pos {
	int y;
	int x;
};

int N, K, L;
int arr[101][101];			//보드
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dir = 1;
deque<pos> dq;
int cnt;
char direction[10001];		//시간 X이후 움직일 방향 저장할 배열

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		direction[a] = b;
	}

	dq.push_back({ 1,1 });
	arr[1][1] = 2;

	while (1)
	{
		int fy = dq.front().y;	//머리
		int fx = dq.front().x;
		int by = dq.back().y;	//꼬리
		int bx = dq.back().x;

		int yy = fy + dy[dir];	//이동할 좌표
		int xx = fx + dx[dir];

		cnt++;

		if (arr[yy][xx] == 2 || yy<1 || yy>N || xx<1 || xx>N) {	//몸통이거나 벽이라면
			printf("%d", cnt);
			return 0;
		}

		if (arr[yy][xx] != 1) {	//사과를 먹지 않으면
			arr[by][bx] = 0;
			dq.pop_back();
		}

		arr[yy][xx] = 2;
		dq.push_front({ yy,xx });

		if (direction[cnt] == 'L') {
			dir--;
		}
		else if (direction[cnt] == 'D') {
			dir++;
		}

		if (dir < 0) {
			dir = 3;
		}
		if (dir > 3) {
			dir = 0;
		}
	}
}
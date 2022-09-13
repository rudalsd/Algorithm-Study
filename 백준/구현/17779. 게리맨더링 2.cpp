#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int arr[20][20];
int temp[20][20];
int d[2];
int y, x;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int population;
int ans = 987654321;

int bfs(int num)	//1 ~ 4구역 표시
{
	queue<pair<int, int>> q;
	int cury, curx;
	if (num == 1) {
		cury = 0;
		curx = 0;
	}
	else if (num == 2) {
		curx = N - 1;
		cury = 0;
	}
	else if (num == 3) {
		curx = 0;
		cury = N - 1;
	}
	else {
		curx = N - 1;
		cury = N - 1;
	}
	int ret = arr[cury][curx];
	temp[cury][curx] = num;
	q.push({ cury,curx });

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (temp[yy][xx] == 0) {
					if (num == 1) {
						if (yy >= 0 && yy < y && xx >= 0 && xx <= x + d[0]) {
							temp[yy][xx] = 1;
							ret += arr[yy][xx];
							q.push({ yy,xx });
						}
					}
					else if (num == 2) {
						if (yy >= 0 && yy <= y - d[0] + d[1] && xx > x + d[0] && xx <= N - 1) {
							temp[yy][xx] = 2;
							ret += arr[yy][xx];
							q.push({ yy,xx });
						}
					}
					else if (num == 3) {
						if (yy >= y && yy <= N - 1 && xx >= 0 && xx < x + d[1]) {
							temp[yy][xx] = 3;
							ret += arr[yy][xx];
							q.push({ yy,xx });
						}
					}
					else {
						if (yy > y - d[0] + d[1] && yy <= N - 1 && xx >= x + d[1] && xx <= N - 1) {
							temp[yy][xx] = 4;
							ret += arr[yy][xx];
							q.push({ yy,xx });
						}
					}
				}
			}
		}
	}

	return ret;
}

int setMap()	//5구역 표시
{
	for (int i = 0; i <= d[0]; i++) {
		int y1 = y - i;
		int x1 = x + i;
		int y2 = y + d[1] - i;
		int x2 = x + d[1] + i;
		temp[y1][x1] = 5;
		temp[y2][x2] = 5;
	}

	for (int i = 0; i <= d[1]; i++) {
		int y1 = y + i;
		int x1 = x + i;
		int y2 = y - d[0] + i;
		int x2 = x + d[0] + i;
		temp[y1][x1] = 5;
		temp[y2][x2] = 5;
	}

	int pop[6] = { 0 };
	pop[5] = population;
	for (int i = 1; i <= 4; i++) {	//각 구역별 인구수 구하기
		pop[i] = bfs(i);
		pop[5] -= pop[i];
	}

	sort(pop, pop + 6);
	int ret = pop[5] - pop[1];

	return ret;
}

void dfs(int level)
{
	if (level == 2) {
		if (x + d[0] + d[1] >= N || y + d[1] >= N || y - d[0] < 0) return;
		memset(temp, 0, sizeof(temp));
		int ret = min(ans, setMap());
		if (ret < ans) {	//최솟값 ans에 저장
			ans = ret;
		}
		return;
	}

	for (int i = 1; i <= N; i++) {	//d1, d2의 조합
		d[level] = i;
		dfs(level + 1);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			population += arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			y = i;
			x = j;
			dfs(0);
		}
	}

	printf("%d", ans);
}
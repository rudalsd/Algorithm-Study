#include<iostream>

using namespace std;

struct pos {
	int r;
	int c;
	int s;
};

int N, M, K;
int arr[51][51];
pos cal[6];
int visited[6];
int ans = 987654321;

void lotate(pos cur)	//배열 돌리가
{
	int r, c, s;
	r = cur.r;
	c = cur.c;
	s = cur.s;


	for (int i = s; i > 0; i--) {
		int temp = arr[r - i][c - i];
		for (int j = r - i; j < r + i; j++) {
			arr[j][c - i] = arr[j + 1][c - i];
		}
		for (int j = c - i; j < c + i; j++) {
			arr[r + i][j] = arr[r + i][j + 1];
		}
		for (int j = r + i; j > r - i; j--) {
			arr[j][c + i] = arr[j - 1][c + i];
		}
		for (int j = c + i; j > c - i; j--) {
			arr[r - i][j] = arr[r - i][j - 1];
		}
		arr[r - i][c - i + 1] = temp;
	}

	int de = -1;
}

void dfs(int level)	//순열 뽑기
{
	if (level == K) {
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += arr[i][j];
			}
			ans = min(ans, sum);
		}
		return;
	}

	int temp[51][51] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			lotate(cal[i]);
			dfs(level + 1);
			visited[i] = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		cal[i] = { r,c,s };
	}

	dfs(0);

	printf("%d", ans);
}
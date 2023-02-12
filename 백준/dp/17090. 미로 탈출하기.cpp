#include<iostream>
#include<cstring>

using namespace std;

int N, M;
char arr[501][501];
int visited[505][505];

int dfs(int r, int c)
{
	if (visited[r][c] != -1) return visited[r][c];
	visited[r][c] = 0;

	if (arr[r][c] == 'U') {
		if (r == 0) return visited[r][c] = 1;
		else return visited[r][c] = dfs(r - 1, c);
	}
	else if (arr[r][c] == 'R') {
		if (c == M - 1) return visited[r][c] = 1;
		else return visited[r][c] = dfs(r, c + 1);
	}
	else if (arr[r][c] == 'D') {
		if (r == N - 1) return visited[r][c] = 1;
		else return visited[r][c] = dfs(r + 1, c);
	}
	else {
		if (c == 0) return visited[r][c] = 1;
		else return visited[r][c] = dfs(r, c - 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == -1) {
				if (dfs(i, j)) ans++;
			}
			else if (visited[i][j] == 1) ans++;
		}
	}

	printf("%d", ans);
}
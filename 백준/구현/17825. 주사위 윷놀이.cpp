#include<iostream>

using namespace std;

int arr[10];
int ans;
int cur[4];
int visited[32];
int map[32] = {		//게임판
	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,28,27,26,25,30,35
};

int move(int cur, int dice)	//게임판의 이동 경로
{
	for (int i = 0; i < dice; i++) {
		if (cur == 5 && i == 0) {
			cur = 21;
		}
		else if (cur == 10 && i == 0) {
			cur = 24;
		}
		else if (cur == 15 && i == 0) {
			cur = 26;
		}
		else if (cur == 23 || cur == 25) {
			cur = 29;
		}
		else if (cur == 31) {
			cur = 20;
		}
		else if (cur == 20) {
			cur = 32;
		}
		else {
			cur++;
		}

		if (cur > 31) {
			return 32;
		}
	}

	return cur;
}

void dfs(int level, int sum)
{
	if (level == 10) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cur[i] > 31) continue;
		int a = cur[i];
		cur[i] = move(a, arr[level]);	//도착점
		if (visited[cur[i]] == 1) {	//도착점에 말이 있다면
			cur[i] = a;
			continue;
		}
		if (cur[i] <= 31) { //도착 칸에 도착했다면
			sum += map[cur[i]];
			visited[cur[i]] = 1;
		}
		visited[a] = 0;
		dfs(level + 1, sum);
		visited[a] = 1;
		if (cur[i] <= 31) { //도착 칸에 도착했다면
			visited[cur[i]] = 0;
			sum -= map[cur[i]];
		}
		cur[i] = a;
	}
}

int main()
{
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	dfs(0, 0);

	printf("%d", ans);
}
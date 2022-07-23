#include<iostream>
#include<cmath>

using namespace std;

struct acc {		//사고의 위치 struct
	int y;
	int x;
};

int N, W;

acc arr[1001];		//사고의 위치를 저장할 배열
int dp[1001][1001];	//dp[a][b] a는 1번 자동차, b는 2번 자동차의 현재 사건 위치

int dist(acc a, acc b)		//a점과 b점의 거리 return
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int dfs(int a, int b)
{
	if (a == W || b == W) return 0;	//마지막 사건이라면
	if (dp[a][b] != 0) return dp[a][b];	//한번이라도 저장되었다면

	int nAcc = max(a, b) + 1;	//다음 사고 번호
	int dist1, dist2;

	if (a == 0) {		//1번 자동차가 움직였을 때의 거리
		dist1 = dist(arr[nAcc], { 1,1 });
	}
	else {
		dist1 = dist(arr[nAcc], arr[a]);
	}
	if (b == 0) {		//2번 자동차가 움직였을 때의 거리
		dist2 = dist(arr[nAcc], { N,N });
	}
	else {
		dist2 = dist(arr[nAcc], arr[b]);
	}

	return dp[a][b] = min(dist1 + dfs(nAcc, b), dist2 + dfs(a, nAcc));
}

void route(int a, int b)
{
	if (a == W || b == W) return;

	int nAcc = max(a, b) + 1;
	int dist1, dist2;

	if (a == 0) {
		dist1 = dist(arr[nAcc], { 1,1 });
	}
	else {
		dist1 = dist(arr[nAcc], arr[a]);
	}
	if (b == 0) {
		dist2 = dist(arr[nAcc], { N,N });
	}
	else {
		dist2 = dist(arr[nAcc], arr[b]);
	}

	if (dp[nAcc][b] + dist1 < dp[a][nAcc] + dist2) {
		printf("1\n");		//1번 자동차가 움직이는 게 가장 짧은 거리일 때
		route(nAcc, b);
	}
	else {					//2번 자동차가 움직이는 게 가장 짧은 거리일 때
		printf("2\n");
		route(a, nAcc);
	}

}

int main()
{
	cin >> N >> W;

	for (int i = 1; i <= W; i++) {
		scanf("%d %d", &arr[i].y, &arr[i].x);
	}

	printf("%d\n", dfs(0, 0));
	route(0, 0);
}
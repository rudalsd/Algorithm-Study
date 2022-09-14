#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
int arr[51][51];
int temp[51][51];
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
vector<pair<int, int>> cloud;

void makeCloud()	//구름 만들기
{
	cloud.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp[i][j] != 1 && arr[i][j] >= 2) {
				cloud.push_back({ i,j });
				arr[i][j] -= 2;
			}
		}
	}
	memset(temp, 0, sizeof(temp));
}

void bug()		//물복사버그
{
	for (auto next : cloud) {
		int cnt = 0;
		for (int i = 2; i <= 8; i += 2) {
			int yy = next.first + dy[i];
			int xx = next.second + dx[i];
			if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
				if (arr[yy][xx] > 0) cnt++;
			}
		}
		arr[next.first][next.second] += cnt;
	}
}

void rain()		//비 내리기
{
	for (auto next : cloud) {
		int y = next.first;
		int x = next.second;
		temp[y][x] = 1;
		arr[y][x]++;
	}
}

void move(int d, int s)	//구름 이동
{
	for (int i = 0; i < cloud.size(); i++) {
		int yy = (cloud[i].first + dy[d] * s) % N;
		int xx = (cloud[i].second + dx[d] * s) % N;
		if (yy < 1) yy += N;
		if (xx < 1)xx += N;
		cloud[i].first = yy;
		cloud[i].second = xx;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	cloud.push_back({ N,1 });
	cloud.push_back({ N,2 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 1,2 });

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;
		scanf("%d %d", &d, &s);
		move(d, s);
		rain();
		bug();
		makeCloud();
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += arr[i][j];
		}
	}

	printf("%d", ans);
}
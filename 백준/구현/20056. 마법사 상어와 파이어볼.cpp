#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct fire {
	int m;
	int s;
	int d;
};

int N, M, K;
vector<fire> arr[51][51];
vector<fire> temp[51][51];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dir[2][4] = { 0,2,4,6,1,3,5,7 };

int getM(int y, int x) //질량의 합
{
	int ret = 0;

	for (auto next : arr[y][x]) {
		ret += next.m;
	}

	return ret;
}

bool odd(vector<int> D)	//방향이 모두 홀수인 지
{
	for (auto next : D) {
		if (next % 2 == 0) {
			return false;
		}
	}

	return true;
}

bool even(vector<int> D) //방향이 모두 짝수인 지
{
	for (auto next : D) {
		if (next % 2 == 1) {
			return false;
		}
	}

	return true;
}

void comb(int y, int x)	//파이어볼이 2개 이상일 때 합치기
{
	int cnt = temp[y][x].size();
	int M, S;
	M = S = 0;
	vector<int> D;
	for (auto& next : temp[y][x]) {
		int m = next.m;
		int s = next.s;
		int d = next.d;

		M += m;
		S += s;
		D.push_back(d);
	}

	M /= 5;
	S /= cnt;

	if (M != 0) {
		if (odd(D) || even(D)) {
			for (int i = 0; i < 4; i++) {
				arr[y][x].push_back({ M,S,dir[0][i] });
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				arr[y][x].push_back({ M,S,dir[1][i] });
			}
		}
	}
}

void after() {	//모든 파이어볼이 이동한 후
	memset(arr, 0, sizeof(arr));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp[i][j].size() >= 2) {
				comb(i, j);
			}
			else if (temp[i][j].size() == 1) {
				arr[i][j] = temp[i][j];
			}
		}
	}
}

void move(int y, int x)	//파이어볼 이동
{
	for (auto& next : arr[y][x]) {
		int m = next.m;
		int s = next.s;
		int d = next.d;

		int yy = y + dy[d] * s;
		int xx = x + dx[d] * s;
		if (yy > N) {
			yy %= N;
		}
		if (yy < 1) {
			yy = -yy % N;
			yy = N - yy;
		}
		if (xx > N) {
			xx %= N;
		}
		if (xx < 1) {
			xx = -xx % N;
			xx = N - xx;
		}

		temp[yy][xx].push_back({ m,s,d });
	}
}

void check()	//파이어볼이 있는 지
{
	memset(temp, 0, sizeof(temp));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size()) {
				move(i, j);
			}
		}
	}

	after();
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;

		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);

		arr[r][c].push_back({ m,s,d });
	}

	for (int i = 0; i < K; i++) {
		check();
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].size()) {
				ans += getM(i, j);
			}
		}
	}

	printf("%d", ans);
}
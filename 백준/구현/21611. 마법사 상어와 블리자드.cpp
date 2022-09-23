#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M;
int arr[51][51];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int y, x;

int ans = 0;

vector<int> setting(vector<int> vect)	//구슬이 모두 파괴된 후 재 세팅
{
	vector<int> temp;
	int cnt = 1;

	if (vect.size() == 0) return vect;

	for (int i = 1; i < min((int)vect.size(), N * N - 1); i++) {
		if (vect[i] == vect[i - 1]) {
			cnt++;
		}
		else {
			temp.push_back(cnt);
			temp.push_back(vect[i - 1]);
			cnt = 1;
		}
		if (temp.size() >= N * N - 1) break;
	}

	temp.push_back(cnt);
	temp.push_back(vect[vect.size() - 1]);

	return temp;
}

vector<int> remove(vector<int> vect)	//같은 구슬이 4개 이상 연속으로 있다면 파괴
{
	while (1)
	{
		if (vect.size() == 0) return vect;
		vector<int> temp;
		bool flag = false;
		int cnt = 1;

		for (int i = 1; i < min((int)vect.size(), N * N - 1); i++) {
			if (vect[i] == vect[i - 1]) {
				cnt++;
			}
			else {
				if (cnt < 4) {
					for (int j = 0; j < cnt; j++) {
						temp.push_back(vect[i - 1]);
					}
				}
				else {
					ans += vect[i - 1] * cnt;
					flag = true;
				}
				cnt = 1;
			}
		}

		if (cnt < 4) {
			for (int j = 0; j < cnt; j++) {
				temp.push_back(vect[vect.size() - 1]);
			}
		}
		else {
			ans += vect[vect.size() - 1] * cnt;
			flag = true;
		}

		vect = temp;

		if (flag == false) {
			break;
		}
	}

	return vect;
}

void move()		//구슬 움직이기
{
	vector<int> vect;
	y = x = N / 2 + 1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			for (int j = 0; j < i; j++) {
				x--;
				if (arr[y][x] != 0) {
					cnt = 0;
					vect.push_back(arr[y][x]);
				}
				else {
					cnt++;
				}
				if (cnt == 2) break;
			}
			if (cnt == 2) break;
			for (int j = 0; j < i; j++) {
				y++;
				if (arr[y][x] != 0) {
					cnt = 0;
					vect.push_back(arr[y][x]);
				}
				else {
					cnt++;
				}
				if (cnt == 2) break;
			}
			if (cnt == 2) break;
		}
		else {
			for (int j = 0; j < i; j++) {
				x++;
				if (arr[y][x] != 0) {
					cnt = 0;
					vect.push_back(arr[y][x]);
				}
				else {
					cnt++;
				}
				if (cnt == 2) break;
			}
			if (cnt == 2) break;
			for (int j = 0; j < i; j++) {
				y--;
				if (arr[y][x] != 0) {
					cnt = 0;
					vect.push_back(arr[y][x]);
				}
				else {
					cnt++;
				}
				if (cnt == 2) break;
			}
			if (cnt == 2) break;
		}
	}

	vect = remove(vect);

	vect = setting(vect);

	memset(arr, 0, sizeof(arr));

	int idx = 0;

	y = x = N / 2 + 1;

	for (int i = 1; i <= N; i++) {		//세팅된 구슬 갱신
		if (i % 2 == 1) {
			for (int j = 0; j < i; j++) {
				if (idx >= vect.size()) break;
				x--;
				if (x < 1) break;
				arr[y][x] = vect[idx];
				idx++;
			}
			if (idx >= vect.size() || x < 1) break;
			for (int j = 0; j < i; j++) {
				if (idx >= vect.size()) break;
				y++;
				arr[y][x] = vect[idx];
				idx++;
			}
			if (idx >= vect.size() || x < 1) break;
		}
		else {
			for (int j = 0; j < i; j++) {
				if (idx >= vect.size()) break;
				x++;
				arr[y][x] = vect[idx];
				idx++;
			}
			if (idx >= vect.size() || x < 1) break;
			for (int j = 0; j < i; j++) {
				if (idx >= vect.size()) break;
				y--;
				arr[y][x] = vect[idx];
				idx++;
			}
			if (idx >= vect.size() || x < 1) break;
		}
	}
}

void blizzard(int d, int s) {	//블리자드
	y = x = N / 2 + 1;
	for (int i = 1; i <= s; i++) {
		int yy = y + dy[d] * i;
		int xx = x + dx[d] * i;

		arr[yy][xx] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	y = x = N / 2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;
		scanf("%d %d", &d, &s);

		blizzard(d, s);

		move();
	}

	printf("%d", ans);
}
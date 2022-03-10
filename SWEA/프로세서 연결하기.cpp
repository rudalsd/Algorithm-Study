#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int y;
	int x;
};

int arr[12][12];
vector<pos> vect;
int dy[5] = { -1,1,0,0,0 };
int dx[5] = { 0,0,-1,1,0 };
int cnt;
int N;
int Max, Min;
int answer[13];

int after(int y, int x, int num)
{
	for (int i = 1; i < N; i++) {
		int yy = y + dy[num] * i;
		int xx = x + dx[num] * i;
		if (yy < N && yy >= 0 && xx < N && xx >= 0) {
			if (arr[yy][xx] == 1 || arr[yy][xx] == -1) {
				return 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		int yy = y + dy[num] * i;
		int xx = x + dx[num] * i;
		if (yy < N && yy >= 0 && xx < N && xx >= 0) {
			arr[yy][xx] = -1;
		}
	}

	return 1;
}

void dfs(int level, int cntNow)
{
	if (cntNow + vect.size() - level < Max) return;
	if (level == vect.size())
	{
		if (Max <= cnt) {
			Max = cnt;
			Min = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (arr[i][j] == -1) {
						Min++;
					}
				}
			}
			if (answer[cnt] > Min) {
				answer[cnt] = Min;
			}
		}
		return;
	}
	cntNow = cnt;

	int before[12][12];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			before[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		if (after(vect[level].y, vect[level].x, i)) {
			cnt++;
		}
		dfs(level + 1, cnt);
		cnt = cntNow;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = before[i][j];
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vect.clear();
		cnt = 0;
		Max = 0;
		Min = 999;
		for (int i = 0; i < 13; i++) {
			answer[i] = 999;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (i > 0 && i < N - 1 && j>0 && j < N - 1 && arr[i][j] == 1) {
					vect.push_back({ i,j });
				}
				else if (arr[i][j] == 1) {
					cnt++;
				}
			}
		}

		dfs(0, cnt);

		cout << "#" << t << " " << answer[Max] << endl;
	}
}
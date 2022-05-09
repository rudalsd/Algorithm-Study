#include <iostream>

using namespace std;

int R, C;
char arr[21][21];
int dr[4] = { -1,1,0,0 };												//방향 배열
int dc[4] = { 0,0,-1,1 };
int bucket[120];														//지나온 알파벳을 저장할 배열
int Max = 0;

void dfs(int r, int c, int level)
{
	if (Max < level) {													//가장 멀리 온 level을 Max에 저장
		Max = level;
	}
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
			if (bucket[arr[rr][cc]] != 1) {
				bucket[arr[rr][cc]]++;									//지나온 알파벳 bucket++
				dfs(rr, cc, level + 1);
				bucket[arr[rr][cc]]--;									//나갈 때 --
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	bucket[arr[0][0]] = 1;
	dfs(0, 0, 1);

	cout << Max;
}
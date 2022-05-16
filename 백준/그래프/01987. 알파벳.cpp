#include <iostream>

using namespace std;

int R, C;
char arr[21][21];
int dr[4] = { -1,1,0,0 };												//���� �迭
int dc[4] = { 0,0,-1,1 };
int bucket[120];														//������ ���ĺ��� ������ �迭
int Max = 0;

void dfs(int r, int c, int level)
{
	if (Max < level) {													//���� �ָ� �� level�� Max�� ����
		Max = level;
	}
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
			if (bucket[arr[rr][cc]] != 1) {
				bucket[arr[rr][cc]]++;									//������ ���ĺ� bucket++
				dfs(rr, cc, level + 1);
				bucket[arr[rr][cc]]--;									//���� �� --
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
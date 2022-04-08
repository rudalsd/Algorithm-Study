#include <iostream>

using namespace std;

int N, M;
char arr[55][55];											//�Է� ���� �迭
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dp[55][55];												//�湮�� üũ�� �迭
int visited[55][55];
int Max = 0;

void dfs(int y, int x, int level)
{
	if (Max == -2) {										//Max���� -2��� ���ѷ����̹Ƿ� return
		return;
	}
	if (Max < dp[y][x]) {									//dp���� �ִ��� Max�� ����
		Max = dp[y][x];
	}
	int num = arr[y][x] - '0';

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i] * num;
		int xx = x + dx[i] * num;
		if ((yy >= 0 && yy < N && xx >= 0 && xx < M) && arr[yy][xx] != 'H') {
			if (visited[yy][xx] != 1) {						//visited�迭�� ���� 1�� �ƴ� �� ���
				if (dp[yy][xx] < dp[y][x] + 1) {
					visited[yy][xx] = 1;
					dp[yy][xx] = dp[y][x] + 1;
					dfs(yy, xx, level + 1);
					visited[yy][xx] = 0;
				}
			}
			else {											//visited�迭�� ���� 1�̶�� ��湮�̹Ƿ� ���ѷ���
				Max = -2;
			}
		}

	}
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0, 0);

	cout << Max + 1;
}
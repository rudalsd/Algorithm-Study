#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int N, L, R;
int arr[50][50];		//����
int visited[50][50];	//�湮 ����
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> pos;

void move(int sum)
{
	for (auto next : pos) {	//�̵�
		int y = next.first;
		int x = next.second;
		arr[y][x] = sum / pos.size();
	}
}

int bfs(int y, int x) {		//������ ���� ã��
	queue<pair<int, int>> q;

	q.push({ y,x });

	int ret = arr[y][x];	//������ ������ �� �α���
	pos.push_back({ y,x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				int diff = abs(arr[y][x] - arr[yy][xx]);

				if (diff >= L && diff <= R && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					pos.push_back({ yy,xx });
					ret += arr[yy][xx];
					q.push({ yy,xx });
				}
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int ans = 0;

	while (1) {
		bool flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					pos.clear();
					int sum = bfs(i, j);
					move(sum);	//�̵�
					if (pos.size() > 1) flag = true;	//�̵��� �ѹ��̶� �ߴٸ�
				}
			}
		}

		if (flag == false) {	//�̵��� ���� �ʾҴٸ�
			printf("%d", ans);
			return 0;
		}

		ans++;
	}
}
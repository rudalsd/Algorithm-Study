#include<iostream>
#include<queue>

using namespace std;

int arr[1000][1000];
int visited[1000][1000];

struct Node {
	int y;
	int x;
	int cnt;
};

int main()
{
	int N, M;
	int y2, x2;
	queue<Node> queue;
	int bucket[4] = { 0 };

	cin >> N >> M;

	Node start;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				start = { i,j,0 };
				queue.push(start);
			}
			if (arr[i][j] == 2) {
				y2 = i;
				x2 = j;
			}
		}
	}

	start = { y2,x2,0 };
	queue.push(start);
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };

	while (!queue.empty())
	{
		int curY = queue.front().y;
		int curX = queue.front().x;
		int curNum = arr[curY][curX];
		int curCnt = queue.front().cnt;
		queue.pop();

		if (curNum == 3) continue;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (curNum == 1) {
					if (arr[yy][xx] == 0) {
						visited[yy][xx] = visited[curY][curX] + 1;
						arr[yy][xx] = curNum;
						Node next = { yy,xx,curCnt + 1 };
						queue.push(next);
					}
				}
				else
				{
					if (arr[yy][xx] == 0) {
						visited[yy][xx] = visited[curY][curX] + 1;
						arr[yy][xx] = curNum;
						Node next = { yy,xx,curCnt + 1 };
						queue.push(next);
					}
					else if (arr[yy][xx] == 1 && visited[yy][xx] == visited[curY][curX] + 1) {
						arr[yy][xx] = 3;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != -1)
				bucket[arr[i][j]]++;
		}
	}

	for (int i = 1; i <= 3; i++) {
		cout << bucket[i] << " ";
	}
}
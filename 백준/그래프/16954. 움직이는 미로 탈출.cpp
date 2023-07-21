#include<iostream>
#include<queue>

using namespace std;

char arr[9][8];
int visited[9][8][10];
int temp;
int dy[9] = { -1,-1,0,1,1,1,0,-1,0 };
int dx[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct node {
	int y;
	int x;
	int cnt;
};

void move()
{
	for (int i = 7; i >= 1; i--) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}

	for (int j = 0; j < 8; j++) {
		arr[0][j] = '.';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	queue<node> q;

	q.push({ 8,0,0 });
	visited[8][0][0] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		q.pop();

		if (y == 1 && x == 7) {
			cout << 1;
			return 0;
		}

		if (temp != cnt) {
			temp = cnt;
			move();
		}

		for (int i = 0; i < 8; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 1 && yy < 9 && xx >= 0 && xx < 8) {
				if (arr[yy][xx] == '.' && arr[yy - 1][xx] != '#' && visited[yy][xx][cnt + 1] != 1) {
					visited[yy][xx][cnt + 1] = 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	cout << 0;
}

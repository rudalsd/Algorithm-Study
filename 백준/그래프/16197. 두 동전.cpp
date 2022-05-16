#include <iostream>
#include <queue>

using namespace std;

int N, M;
int x[2], y[2];
char arr[21][21];															//동전을 제외한 맵을 저장
char temp[21][21];															//반복할 때마다 맵에 동전만 추가하기 위한 배열
int visited[20][20][20][20];												//방문 여부를 체크할 배열 y1,x1,y2,x2
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y[2];
	int x[2];
	int cnt;
};

int main()
{
	cin >> N >> M;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				arr[i][j] = '.';											//동전을 제외한 맵을 저장하기 위해 값이 'o'라면 '.'로 변경
				y[cnt] = i;
				x[cnt] = j;
				cnt++;
			}
		}
	}

	queue<pos> q;
	q.push({ {y[0], y[1]}, {x[0], x[1]}, 0 });								//각각의 좌표를 q에 넣기
	visited[y[0]][x[0]][y[1]][x[1]] = 1;

	while (!q.empty())
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		int out;
		int y1 = q.front().y[0];
		int x1 = q.front().x[0];
		int y2 = q.front().y[1];
		int x2 = q.front().x[1];
		int cnt = q.front().cnt;
		temp[y1][x1] = 'o';
		temp[y2][x2] = 'o';
		q.pop();

		if (cnt == 10) continue;											//버튼을 10번 넘게 눌렀으면 continue

		for (int i = 0; i < 4; i++) {
			out = 0;
			int yy1 = y1 + dy[i];											//동전1의 좌표
			int xx1 = x1 + dx[i];
			int yy2 = y2 + dy[i];											//동전2의 좌표
			int xx2 = x2 + dx[i];
			if (yy1 >= N || yy1 < 0 || xx1 >= M || xx1 < 0) {				//밖으로 나가면 out++
				out++;
			}
			if (yy2 >= N || yy2 < 0 || xx2 >= M || xx2 < 0) {
				out++;
			}
			if (out == 1) {													//하나만 나갔다면
				cout << cnt + 1;
				return 0;
			}
			else if (out == 0) {											//하나도 나가지 않았다면
				if (arr[yy1][xx1] == '#') {									//움직인 위치가 벽이면 원위치
					yy1 = y1;
					xx1 = x1;
				}
				if (arr[yy2][xx2] == '#') {
					yy2 = y2;
					xx2 = x2;
				}
				if (yy1 == yy2 && xx1 == xx2) continue;						//같은 좌표에 한번이라도 있다면 무조건 둘 다 같이 떨어지므로 continue
				if (visited[yy1][xx1][yy2][xx2] == 0) {						//이 상태였던 적이 없다면
					visited[yy1][xx1][yy2][xx2] = 1;
					q.push({ {yy1,yy2}, {xx1,xx2}, cnt + 1 });
				}
			}
		}
	}

	cout << -1;
}
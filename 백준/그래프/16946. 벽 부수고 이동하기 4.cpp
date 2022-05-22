#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
char arr[1001][1001];							//값을 입력 받을 배열
int ans[1001][1001];							//정답을 기록할 배열
int visited[1001][1001];						//방문을 체크할 배열
int dy[4] = { -1,1,0,0 };						//방향 배열
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

void bfs(int y, int x)
{
	queue<pos> q;
	vector<pos> vect;

	q.push({ y,x });
	arr[y][x] = 'a';

	int cnt = 1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '0') {
					arr[yy][xx] = 'a';								//배열값을 'a'로 초기화하면서 다시 방문하지 못하게 한다.
					cnt++;											//갈 수 있는 곳의 수를 저장
					q.push({ yy,xx });
				}
				if (arr[yy][xx] == '1' && visited[yy][xx] != 1) {	//벽을 만나면 visited에 기록하고 좌표를 저장
					visited[yy][xx] = 1;
					vect.push_back({ yy,xx });
				}
			}
		}
	}

	for (int i = 0; i < vect.size(); i++) {
		int yy = vect[i].y;
		int xx = vect[i].x;
		visited[yy][xx] = 0;						//방문 기록을 없애고
		ans[yy][xx] += cnt;							//해당 좌표에 cnt값을 더해줌
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') {
				bfs(i, j);							//해당 배열의 값이 '0'이라면
			}										//bfs를 돌린다
			else if (arr[i][j] == '1') {
				ans[i][j]++;						//해당 값이 '1'이라면 총 카운트 수에서 1을 더해준다
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] % 10;					//10으로 나눈 나머지 값을 출력한다.
		}
		cout << endl;
	}
}
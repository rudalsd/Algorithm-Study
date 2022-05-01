#include<iostream>

using namespace std;

int arr[55][55];									//맵
int N, M;
int cy, cx, dir;
int dy1[4] = { 0,-1,0,1 };							//좌회전 방향 배열
int dx1[4] = { -1,0,1,0 };
int dy2[4] = { 1,0,-1,0 };							//후진 방향 배열
int dx2[4] = { 0,-1,0,1 };
int cnt = 0;

int main()
{
	int result = 0;
	cin >> N >> M;
	cin >> cy >> cx >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1)
	{
		if (arr[cy][cx] == 0) {						//지금 있는 자리가 청소가 되지 않은 자리면 -1로 바꾸고 결괏값에 +1
			arr[cy][cx] = -1;
			result++;
		}

		if (cnt == 4) {								//4번 돌았으면 후진 가능한지 체크
			int y = cy + dy2[dir];
			int x = cx + dx2[dir];
			if (arr[y][x] == 1) {					//후진이 불가능하면 탈출
				break;
			}
			else {									//후진이 가능하면 후진 후 cnt 초기화
				cy = y;
				cx = x;
				cnt = 0;
			}
		}

		int yy = cy + dy1[dir];						//좌회전 좌표
		int xx = cx + dx1[dir];

		if (arr[yy][xx] == 0) {						//좌회전 후 직진한 위치가 청소 전이면 이동
			cy = yy;
			cx = xx;
			cnt = 0;
		}
		else {										//그렇지 않다면 이동하지 않고 cnt++
			cnt++;
		}
		dir -= 1;									//좌회전
		if (dir < 0) {
			dir = 3;
		}
	}

	cout << result;
}
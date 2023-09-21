#include<iostream>

using namespace std;

struct robot {
	int y, x;
	int dir;
};

int A, B, N, M;
int m[101][101];
robot arr[101];
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

int move(int num, int re)
{
	int yy = arr[num].y;
	int xx = arr[num].x;
	int dir = arr[num].dir;

	m[yy][xx] = 0;

	for (int i = 0; i < re; i++) {
		yy += dy[dir];
		xx += dx[dir];
		if (yy > 0 && yy <= B && xx > 0 && xx <= A) {
			if (m[yy][xx] != num && m[yy][xx] != 0) {
				return m[yy][xx];
			}
		}
		else {
			return -1;
		}
	}

	m[yy][xx] = num;
	arr[num] = { yy,xx,dir };

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> N >> M;

	for (int i = 1; i <= N; i++) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		if (dir == 'E') {
			m[y][x] = i;
			arr[i] = { y,x,0 };
		}
		else if (dir == 'S') {
			m[y][x] = i;
			arr[i] = { y,x,1 };
		}
		else if (dir == 'W') {
			m[y][x] = i;
			arr[i] = { y,x,2 };
		}
		else {
			m[y][x] = i;
			arr[i] = { y,x,3 };
		}
	}

	while (M--) {
		int num, re;
		char cmd;
		cin >> num >> cmd >> re;

		if (cmd == 'F') {
			int n = move(num, re);
			if (n == -1) {
				cout << "Robot " << num << " crashes into the wall";
				return 0;
			}
			else if (n != 0) {
				cout << "Robot " << num << " crashes into robot " << n;
				return 0;
			}
		}
		else if (cmd == 'R') {
			arr[num].dir += re;
			arr[num].dir %= 4;
		}
		else {
			re %= 4;
			arr[num].dir -= re;
			arr[num].dir = (arr[num].dir + 4) % 4;
		}
	}

	cout << "OK";
}
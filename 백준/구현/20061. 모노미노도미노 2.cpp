#include<iostream>

using namespace std;

int N;
int arr[10][10];
int ans;

void moveB(int num)		//파란색 보드에서 열이 사라졌을 때 움직일 함수
{
	for (int i = num; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			arr[j][i] = arr[j][i - 1];
		}
	}
}

void moveG(int num)		//초록색 보드에서 열이 사라졌을 때 움직일 함수
{
	for (int i = num; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
}

void remove()	//연한 영역에 있거나, 한줄이 완성되면 없애는 함수
{
	for (int i = 9; i >= 6; i--) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (arr[j][i] == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			ans++;
			moveB(i);
			i++;
		}
	}

	for (int i = 9; i >= 6; i--) {
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			ans++;
			moveG(i);
			i++;
		}
	}

	bool flag = true;
	while (flag == true) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			if (arr[i][5] == 1) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			moveB(9);
		}
	}

	flag = true;
	while (flag == true) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			if (arr[5][i] == 1) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			moveG(9);
		}
	}
}

void move(int t, int x, int y)	//처음 블록을 놓았을 때 블록을 움직이는 함수
{
	int idx = 10;

	if (t == 1) {
		for (int i = 0; i < 10; i++) {
			if (arr[i][y] == 1) {
				arr[i - 1][y] = 1;
				break;
			}
			else if (i == 9) {
				arr[i][y] = 1;
			}
		}
		for (int i = 0; i < 10; i++) {
			if (arr[x][i] == 1) {
				arr[x][i - 1] = 1;
				break;
			}
			else if (i == 9) {
				arr[x][i] = 1;
			}
		}
	}
	else if (t == 2) {
		for (int i = 4; i < 10; i++) {
			if (arr[i][y] == 1) {
				idx = min(idx, i);
				break;
			}
		}
		for (int i = 4; i < 10; i++) {
			if (arr[i][y + 1] == 1) {
				idx = min(idx, i);
				break;
			}
		}
		arr[idx - 1][y] = 1;
		arr[idx - 1][y + 1] = 1;

		for (int i = 4; i < 10; i++) {
			if (arr[x][i] == 1) {
				arr[x][i - 1] = 1;
				arr[x][i - 2] = 1;
				break;
			}
			else if (i == 9) {
				arr[x][i] = 1;
				arr[x][i - 1] = 1;
			}
		}
	}
	else {
		for (int i = 4; i < 10; i++) {
			if (arr[x][i] == 1) {
				idx = min(idx, i);
				break;
			}
		}
		for (int i = 4; i < 10; i++) {
			if (arr[x + 1][i] == 1) {
				idx = min(idx, i);
				break;
			}
		}
		arr[x][idx - 1] = 1;
		arr[x + 1][idx - 1] = 1;

		for (int i = 4; i < 10; i++) {
			if (arr[i][y] == 1) {
				arr[i - 1][y] = 1;
				arr[i - 2][y] = 1;
				break;
			}
			else if (i == 9) {
				arr[i][y] = 1;
				arr[i - 1][y] = 1;
			}
		}
	}

	remove();
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);

		move(t, x, y);

		int de = -1;
	}

	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}

	printf("%d\n%d", ans, cnt);
}
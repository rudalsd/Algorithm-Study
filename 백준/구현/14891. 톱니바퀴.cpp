#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string arr[5];
int K;

void move(int num, int dir)	//톱니바퀴 이동
{
	if (dir == 1) {
		char temp = arr[num][7];
		for (int i = 7; i > 0; i--) {
			arr[num][i] = arr[num][i - 1];
		}
		arr[num][0] = temp;
	}
	else {
		char temp = arr[num][0];
		for (int i = 0; i < 7; i++) {
			arr[num][i] = arr[num][i + 1];
		}
		arr[num][7] = temp;
	}
}

void check(int num, int dir, int visited[5])	//움직일지 말지 정하기
{
	visited[num] = 1;
	if (num == 1) {
		if (arr[num][2] != arr[num + 1][6]) {
			if (visited[2] != 1) {
				check(2, dir * -1, visited);
			}
		}
	}
	else if (num == 2) {
		if (arr[num][2] != arr[num + 1][6]) {
			if (visited[3] != 1) {
				check(3, dir * -1, visited);
			}
		}
		if (arr[num][6] != arr[num - 1][2]) {
			if (visited[1] != 1) {
				check(1, dir * -1, visited);
			}
		}
	}
	else if (num == 3) {
		if (arr[num][2] != arr[num + 1][6]) {
			if (visited[4] != 1) {
				check(4, dir * -1, visited);
			}
		}
		if (arr[num][6] != arr[num - 1][2]) {
			if (visited[2] != 1) {
				check(2, dir * -1, visited);
			}
		}
	}
	else {
		if (arr[num][6] != arr[num - 1][2]) {
			if (visited[3] != 1) {
				check(3, dir * -1, visited);
			}
		}
	}

	move(num, dir);
}

int main()
{
	for (int i = 1; i <= 4; i++) {
		cin >> arr[i];
	}
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int num, dir;
		int visited[5] = { 0 };

		scanf("%d %d", &num, &dir);

		check(num, dir, visited);
	}

	int ans = 0;

	for (int i = 1; i <= 4; i++) {
		if (arr[i][0] == '1') {
			ans += pow(2, i - 1);
		}
	}

	printf("%d", ans);
}
#include<iostream>

using namespace std;

int N, M, x, y, K;
int arr[20][20];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dice[3][3];
int temp1;
int temp2;

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		scanf("%d", &dir);
		int yy = y + dy[dir - 1];	//주사위가 움직일 좌표
		int xx = x + dx[dir - 1];
		if (xx >= 0 && xx < N && yy >= 0 && yy < M) {
			if (dir == 1) {	//동쪽
				if (arr[xx][yy] != 0) {
					dice[1][2] = arr[xx][yy];
					arr[xx][yy] = 0;
				}
				else {
					arr[xx][yy] = dice[1][2];
				}
				temp1 = dice[1][0];
				for (int j = 0; j < 2; j++) {
					dice[1][j] = dice[1][j + 1];
				}
				dice[1][2] = temp2;
				temp2 = temp1;
			}
			else if (dir == 2) {	//서쪽
				if (arr[xx][yy] != 0) {
					dice[1][0] = arr[xx][yy];
					arr[xx][yy] = 0;
				}
				else {
					arr[xx][yy] = dice[1][0];
				}
				temp1 = dice[1][2];
				for (int j = 2; j > 0; j--) {
					dice[1][j] = dice[1][j - 1];
				}
				dice[1][0] = temp2;
				temp2 = temp1;
			}
			else if (dir == 3) {	//북쪽
				if (arr[xx][yy] != 0) {
					dice[0][1] = arr[xx][yy];
					arr[xx][yy] = 0;
				}
				else {
					arr[xx][yy] = dice[0][1];
				}
				temp1 = dice[2][1];
				for (int j = 2; j > 0; j--) {
					dice[j][1] = dice[j - 1][1];
				}
				dice[0][1] = temp2;
				temp2 = temp1;
			}
			else {		//남쪽
				if (arr[xx][yy] != 0) {
					dice[2][1] = arr[xx][yy];
					arr[xx][yy] = 0;
				}
				else {
					arr[xx][yy] = dice[2][1];
				}
				temp1 = dice[0][1];
				for (int j = 0; j < 2; j++) {
					dice[j][1] = dice[j + 1][1];
				}
				dice[2][1] = temp2;
				temp2 = temp1;
			}
			printf("%d\n", temp2);
			y = yy;
			x = xx;
		}
	}
}
#include <iostream>

using namespace std;

char arr[10][10];

int garo[10][10];													//가로 칸의 숫자를 저장할 배열
int sero[10][10];													//세로 칸의 숫자를 저장할 배열
int nemo[10][10];													//3x3짜리 사각형 칸의 숫자를 저장할 배열

int cnt = 0;

struct pos {
	int y;
	int x;
};

pos node[100];														//비어져 있는 칸의 좌표를 저장할 배열
int result;

void dfs(int level)
{
	if (result == 1) {												//결과가 나오면 return
		return;
	}
	if (level == cnt) {												//한번 다 채워지면 result = 1로 바꾸고 arr배열 출력
		result = 1;
		for (int i = 0; i < 9; i++) {
			cout << arr[i] << endl;
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int yy = node[level].y;										//아직 그 칸에 한번도 나오지 않은 숫자만 넣기
		int xx = node[level].x;
		if (sero[xx][i] != 1 && garo[yy][i] != 1 && nemo[(yy / 3) * 3 + xx / 3][i] != 1) {
			sero[xx][i] = 1;
			garo[yy][i] = 1;
			nemo[(yy / 3) * 3 + xx / 3][i] = 1;
			arr[yy][xx] = i + '0';
			dfs(level + 1);
			arr[yy][xx] = '0';
			sero[xx][i] = 0;
			garo[yy][i] = 0;
			nemo[(yy / 3) * 3 + xx / 3][i] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == '0') {
				node[cnt] = { i,j };								//비어져 있는 칸의 좌표를 저장
				cnt++;

			}
			else {													//채워져 있을 경우 각각의 배열에 숫자 저장
				int num = arr[i][j] - '0';
				garo[i][num]++;
				sero[j][num]++;
				nemo[(i / 3) * 3 + j / 3][num]++;
			}
		}
	}

	dfs(0);															//dfs 실행
}
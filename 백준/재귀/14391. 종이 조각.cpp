#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[4][4];													//숫자 저장
int visited[4][4];												//0일 때 가로, 1일 때 세로
int ans;
int sum;

void dfs(int y, int x) {
	if (x == M) {												//한 줄 입력이 끝나면 다음 줄로 이동
		y += 1;
		x = 0;
	}
	if (y == N) {												//마지막 칸까지 입력이 끝나면 계산
		sum = 0;
		int temp = 0;
		for (int i = 0; i < N; i++) {							//가로부터 계산
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 0) {						//visited[i][j] == 0이면 
					temp = temp * 10 + arr[i][j];				//temp*10 + arr[i][j]를 temp에 대입
				}
				else {											//아니라면
					sum += temp;								//지금까지 더한 temp값을 sum에 더하고
					temp = 0;									//temp 초기화
				}
			}
			sum += temp;										//마지막 수를 sum에 더하고
			temp = 0;											//temp 초기화
		}
		for (int i = 0; i < M; i++) {							//세로 계산
			for (int j = 0; j < N; j++) {
				if (visited[j][i] == 1) {
					temp = temp * 10 + arr[j][i];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
			temp = 0;
		}

		if (ans < sum) {										//sum의 값이 ans보다 더 크다면 ans를 sum으로 갱신
			ans = sum;
		}

		return;
	}

	visited[y][x] = 0;
	dfs(y, x + 1);

	visited[y][x] = 1;
	dfs(y, x + 1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	dfs(0, 0);

	cout << ans;
}
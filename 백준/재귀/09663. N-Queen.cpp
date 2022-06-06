#include <iostream>

using namespace std;

int N;
int qx[15];		//퀸의 x좌표 저장
int up[30];		//퀸의 오른쪽 위 대각선 방향 체크
int down[30];	//퀸의 오른쪽 아래 대각선 방향 체크
int cnt;
int ans;

int check(int y, int x)	//y,x 좌표에 퀸을 놓을 수 있는지 체크하는 함수
{
	if (qx[x] || up[y + x] || down[y - x + N - 1]) {
		return 0;		//놓을 수 없다면 0 return
	}

	return 1;			//놓을 수 있다면 1 return
}

void dfs(int y)			//한 줄에 하나의 퀸만 들어갈 수 있으므로 
{						//퀸을 놓으면 바로 y+1값으로 dfs 진행
	if (cnt == N) {
		ans++;
		return;
	}
	if (y >= N) {
		return;
	}

	for (int x = 0; x < N; x++) {
		if (check(y, x))
		{
			qx[x]++;		//x좌표 저장
			up[y + x]++;	//대각선 방향 저장
			down[y - x + N - 1]++;
			cnt++;
			dfs(y + 1);
			cnt--;
			qx[x]--;
			up[y + x]--;
			down[y - x + N - 1]--;
		}
	}
}

int main()
{
	cin >> N;

	dfs(0);

	cout << ans;
}
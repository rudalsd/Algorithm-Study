#include <iostream>
#include <cstring>

using namespace std;

int arr[100001];
int visited[100001];											//방문을 체크할 배열
int isTeam[100001];												//팀이 가능한지 체크할 배열
int flag = 0;													//팀이 가능한지 불가능한지 명시할 flag 변수
int cnt = 0;

void dfs(int cur)
{
	if (arr[cur] == cur) {										//본인을 선택했다면
		isTeam[cur] = 1;										//본인의 팀 가능 배열 1로 갱신
		flag = -1;												//백트래킹으로 나를 선택한 사람들 줄줄이 isTeam -1로 바꾸기 위해
		return;
	}
	if (isTeam[cur] == -1) {									//팀이 불가능하다면
		flag = -1;												//백트래킹으로 나를 선택한 사람들 줄줄이 isTeam -1로 바꾸기 위해
		return;
	}
	if (visited[cur] != 1) {									//방문하지 않았다면
		visited[cur] = 1;										//방문 체크 후
		dfs(arr[cur]);											//dfs
		visited[cur] = 0;										//나올 때는 visited배열 초기화
		if (flag == -1) {										//flag가 -1이라면
			isTeam[cur] = -1;									//팀이 불가능하므로 isTeam = -1
			cnt++;
		}
		else {													//아니라면 팀이 가능하므러
			isTeam[cur] = 1;									//isTeam = 1
		}
		if (flag == cur) {										//만약 백트래킹 중 하나의 사이클이 완성된다면 나머지는 팀이 불가능하므로
			flag = -1;											//flag = -1
		}
	}
	else {														//만약 방문한 곳에 한번 더 방문한다면
		flag = cur;												//flag를 cur로 바꿔줌
		return;
	}
}

int main()
{
	int T;
	cin >> T;
	int n;

	for (int t = 0; t < T; t++) {
		cin >> n;
		cnt = 0;
		memset(isTeam, 0, 4 * (n + 1));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= n; i++) {
			flag = 0;
			if (isTeam[i] == 0) {
				dfs(i);
			}
		}

		cout << cnt << endl;;
	}
}
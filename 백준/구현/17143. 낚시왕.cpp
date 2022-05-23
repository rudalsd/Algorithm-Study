#include <iostream>
#include <cstring>

using namespace std;

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
};

int R, C, M;
shark arr[10001];					//각 상어의 정보를 저장발 배열
int dr[5] = { 0,-1,1,0,0 };			//방향 배열
int dc[5] = { 0,0,0,1,-1 };
int visited[101][101];				//상어가 도착한 장소에 상어가 있는지 체크하기 위한 배열

int main()
{
	cin >> R >> C >> M;
	int idx = 1;
	int sum = 0;

	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		if (d < 3) {				//일정 속도 이상이면 여러번 제자리로 돌아오기 때문에
			s %= 2 * (R - 1);		//총 (길이-1)*2로 나눈 나머지 값을 속도에 넣어준다.
		}
		else {
			s %= 2 * (C - 1);
		}
		arr[i] = { r,c,s,d,z };
	}

	while (idx <= C)
	{
		memset(visited, 0, sizeof(visited));
		int min = 999;
		int x = 987654321;
		for (int i = 1; i <= M; i++) {		//현재 사람과 같은 위치에 있는 상어 중
			if (arr[i].r == 0) continue;	//가장 땅에 가까운 상어의 번호를 x에 저장
			if (idx == arr[i].c) {
				if (min > arr[i].r) {
					min = arr[i].r;
					x = i;
				}
			}
		}
		if (x != 987654321) {				//x가 경신 되었다면 그 상어를 없애고
			sum += arr[x].z;				//sum에 크기를 더해준다.
			arr[x] = { 0 };
		}

		for (int i = 1; i <= M; i++) {		//모든 상어를 움직인다.
			if (arr[i].r == 0) continue;
			int rr = arr[i].r;
			int cc = arr[i].c;
			for (int j = 0; j < arr[i].s; j++) {
				rr += dr[arr[i].d];
				cc += dc[arr[i].d];
				if (arr[i].d == 1) {
					if (rr == 1) {
						arr[i].d = 2;
					}
					else if (rr < 1) {
						arr[i].d = 2;
						rr = 2;
					}
				}
				else if (arr[i].d == 2) {
					if (rr == R) {
						arr[i].d = 1;
					}
					else if (rr > R) {
						rr = R - 1;
						arr[i].d = 1;
					}
				}
				else if (arr[i].d == 3) {
					if (cc == C) {
						arr[i].d = 4;
					}
					else if (cc > C) {
						cc = C - 1;
						arr[i].d = 4;
					}
				}
				else if (arr[i].d == 4) {
					if (cc == 1) {
						arr[i].d = 3;
					}
					else if (cc < 1) {
						arr[i].d = 3;
						cc = 2;
					}
				}
			}
			if (visited[rr][cc] == 0) {		//만약 처음 상어가 도착했다면
				visited[rr][cc] = i;		//visited배열에 상어 번호를 저장
				arr[i].r = rr;
				arr[i].c = cc;
			}
			else {							//이미 와 있던 상어가 있다면
				if (arr[i].z > arr[visited[rr][cc]].z) {
					arr[visited[rr][cc]] = { 0 };
					visited[rr][cc] = i;	//크기를 비교 후 더 크면
					arr[i].r = rr;			//visited배열을 경신해준다
					arr[i].c = cc;
				}
				else {
					arr[i] = { 0 };			//더 작다면 더 작은 상어를 없앤다.
				}
			}
		}
		idx++;				//오른쪽으로 옮긴다.
	}

	cout << sum;		//결과 출력
}
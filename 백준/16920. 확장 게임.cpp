#include <iostream>
#include <queue>

using namespace std;

int N, M, P;
int S[15];																//이동 가능한 거리 저장할 배열
char arr[1100][1100];
int result[15];															//개수를 저장할 배열
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Node {
	int P;						//플레이어 번호
	int y;						//y 좌표
	int x;						//x 좌표
	int cnt;					//이동 거리
	int time;					//게임 턴
};

struct cmp {																//time이 작을수록 앞으로 같다면 P번호가 낮을수록 앞으로 같다면 cnt가 작을수록 앞으로 정렬
	bool operator()(Node right, Node left) {
		if (left.time < right.time) return true;
		if (left.time > right.time) return false;
		if (left.P < right.P) return true;
		if (left.P > right.P) return false;
		return left.cnt < right.cnt;

	}
};

priority_queue<Node, vector<Node>, cmp> pq;

int main()
{
	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] >= '1' && arr[i][j] <= '9') {				//배열을 돌면서 숫자가 있다면 result[P]값++
				pq.push({ arr[i][j] - '0',i,j,0,0 });
				result[arr[i][j] - '0']++;
			}
		}
	}

	while (!pq.empty())
	{
		int P = pq.top().P;
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().cnt;
		int time = pq.top().time;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '.') {											//다음 갈 곳이 비어있다면
					arr[yy][xx] = P + '0';											//배열을 P로 바꾸고
					result[P]++;													//결괏값에 +1
					if (cnt + 1 == S[P]) {											//다 왔다면
						pq.push({ P,yy,xx,0,time + 1 });							//pq에 cnt를 0로 초기화하고, time에 +1을 해줘서 push
					}
					else {															//아직 더 갈 수 있다면
						pq.push({ P,yy,xx,cnt + 1,time });							//cnt++
					}
				}
			}
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << result[i] << " ";
	}
}
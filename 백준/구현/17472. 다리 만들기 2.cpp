#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int arr[10][10];
int visited[10][10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> pos[7];
vector<pair<int, int>> list[7];
int vect[7];

struct node {
	int start;
	int end;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int find(int num)	//부모 찾기
{
	if (vect[num] == num) return num;
	return vect[num] = find(vect[num]);
}

void Union(int a, int b)	//같은 부모를 가지고 있는지
{
	int pa = find(a);
	int pb = find(b);

	vect[pb] = pa;
}

void getDist(int a, int b) //두 섬 사이의 최단 거리 구하기
{
	int ret = 987654321;

	for (auto A : pos[a]) {
		for (auto B : pos[b]) {
			if (A.first == B.first) {
				bool flag = false;
				if (A.second > B.second) {
					for (int i = B.second + 1; i < A.second; i++) {
						if (arr[A.first][i] == 1) {
							flag = true;
							break;
						}
					}
					if (flag == false) {
						if (A.second - B.second - 1 != 1) {
							ret = min(ret, A.second - B.second - 1);
						}
					}
				}
				else {
					for (int i = A.second + 1; i < B.second; i++) {
						if (arr[A.first][i] == 1) {
							flag = true;
							break;
						}
					}
					if (flag == false) {
						if (B.second - A.second - 1 != 1) {
							ret = min(ret, B.second - A.second - 1);
						}
					}
				}
			}
			if (A.second == B.second) {
				bool flag = false;
				if (A.first > B.first) {
					for (int i = B.first + 1; i < A.first; i++) {
						if (arr[i][A.second] == 1) {
							flag = true;
							break;
						}
					}
					if (flag == false) {
						if (A.first - B.first - 1 != 1) {
							ret = min(ret, A.first - B.first - 1);
						}
					}
				}
				else {
					for (int i = A.first + 1; i < B.first; i++) {
						if (arr[i][A.second] == 1) {
							flag = true;
							break;
						}
					}
					if (flag == false) {
						if (B.first - A.first - 1 != 1) {
							ret = min(ret, B.first - A.first - 1);
						}
					}
				}
			}
		}
	}

	if (ret != 987654321) {
		list[a].push_back({ b,ret });
	}
}

void bfs(int y, int x, int cnt)	//이어져 있는 땅 찾기
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	pos[cnt].push_back({ y,x });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
					pos[cnt].push_back({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int cnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && visited[i][j] != 1) {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	cnt;

	for (int i = 1; i < cnt; i++) {
		vect[i] = i;
		for (int j = 1; j < cnt; j++) {
			if (i != j) {
				getDist(i, j);
			}
		}
	}

	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i < cnt; i++) {
		for (auto next : list[i]) {
			pq.push({ i,next.first,next.second });
		}
	}

	int ans = 0;

	while (!pq.empty()) {
		int start = pq.top().start;
		int end = pq.top().end;
		int dist = pq.top().dist;
		pq.pop();

		if (find(start) != find(end)) {
			Union(start, end);
			ans += dist;
		}
	}

	for (int i = 1; i < cnt; i++) {
		for (int j = 1; j < cnt; j++) {
			if (i != j) {
				if (find(i) != find(j)) {
					printf("%d", -1);
					return 0;
				}
			}
		}
	}

	printf("%d", ans);
}
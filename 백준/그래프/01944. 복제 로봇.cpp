#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct node {
	int u;
	int v;
	int d;
};

bool cmp(node left, node right)
{
	return left.d < right.d;
}

int N, M;
char arr[51][51];
int check[251][251];
int key[51][51];
vector<node> edge;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int vect[251];

void getEdge(int y, int x)
{
	int u = key[y][x];
	int visited[50][50] = { 0 };
	queue<node> q;
	q.push({ y,x,0 });
	visited[y][x] = 1;

	while (!q.empty()) {
		const int y = q.front().u;
		const int x = q.front().v;
		const int cnt = q.front().d;
		q.pop();

		if ((arr[y][x] == 'S' || arr[y][x] == 'K') && cnt != 0) {
			int v = key[y][x];
			if (check[u][v] != 1 && check[v][u] != 1) {
				edge.push_back({ u,v,cnt });
				check[u][v] = 1;
				check[v][u] = 1;
			}
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy > 0 && yy < N - 1 && xx>0 && xx < N - 1) {
				if (arr[yy][xx] != '1' && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}
}

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 1; i <= M; i++) {
		vect[i] = i;
	}

	int cnt = 1;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (arr[i][j] == 'S') {
				key[i][j] = 0;
			}
			else if(arr[i][j] == 'K'){
				key[i][j] = cnt++;
			}
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (arr[i][j] == 'S' || arr[i][j] == 'K') {
				getEdge(i, j);
			}
		}
	}

	sort(edge.begin(), edge.end(), cmp);

	int ans = 0;
	cnt = 0;

	for (auto& next : edge) {
		const int u = next.u;
		const int v = next.v;
		const int d = next.d;

		if (Find(u) != Find(v)) {
			Union(u, v);
			ans += d;
			cnt++;
		}
	}

	if (cnt == M) {
		printf("%d", ans);
		return 0;
	}

	printf("-1");
}
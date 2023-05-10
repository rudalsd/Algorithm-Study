#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct node {
	int a;
	int b;
	int D;
};

bool cmp(node left, node right)
{
	return left.D < right.D;
}

int M, N;
int map[500][500];
vector<int> waypoint;
vector<node> arr;
int vect[250000];
int cnt = -1;
int dy[2] = { 1,0 };
int dx[2] = { 0,1 };
int ans;

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
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			vect[i * N + j] = i * N + j;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			scanf("%d", &num);

			if (num == 1) cnt++;

			waypoint.push_back(num);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				int ii = i + dy[k];
				int jj = j + dx[k];

				if (ii >= 0 && ii < M && jj >= 0 && jj < N) {
					arr.push_back({ i * N + j, ii * N + jj, abs(map[i][j] - map[ii][jj]) });
				}
			}
		}
	}

	sort(arr.begin(), arr.end(), cmp);

	for (auto& next : arr) {
		int pa = Find(next.a);
		int pb = Find(next.b);
		const int D = next.D;

		if (pa != pb) {
			if (waypoint[pa] == 1 && waypoint[pb] == 1) {
				cnt--;
			}
			else if (waypoint[pa] == 0 && waypoint[pb] == 1) {
				swap(pa, pb);
			}

			ans = max(ans, D);

			Union(pa, pb);
		}

		if (cnt == 0) {
			printf("%d", ans);
			return 0;
		}
	}
}
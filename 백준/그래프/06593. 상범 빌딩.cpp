#include<iostream>
#include<queue>

using namespace std;

int L, R, C;
char arr[31][31][31];
int dl[6] = { 0,0,0,0,-1,1 };
int dr[6] = { -1,1,0,0,0,0 };
int dc[6] = { 0,0,-1,1,0,0 };
int Sl, Sr, Sc, El, Er, Ec;

struct node {
	int l;
	int r;
	int c;
	int cnt;
};

int main()
{
	while (1) {
		scanf("%d %d %d", &L, &R, &C);

		if (L == 0 && R == 0 && C == 0) {
			return 0;
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				scanf("%s", arr[i][j]);
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (arr[i][j][k] == 'S') {
						Sl = i;
						Sr = j;
						Sc = k;
					}
				}
			}
		}

		queue<node> q;
		int visited[31][31][31] = { 0 };

		q.push({ Sl,Sr,Sc,0 });
		visited[Sl][Sr][Sc] = 1;

		int ans = 0;

		while (!q.empty()) {
			const int l = q.front().l;
			const int r = q.front().r;
			const int c = q.front().c;
			const int cnt = q.front().cnt;
			q.pop();

			if (arr[l][r][c] == 'E') {
				ans = cnt;
				break;
			}

			for (int i = 0; i < 6; i++) {
				const int ll = l + dl[i];
				const int rr = r + dr[i];
				const int cc = c + dc[i];

				if (ll >= 0 && ll < L && rr >= 0 && rr < R && cc >= 0 && cc < C) {
					if ((arr[ll][rr][cc] == '.' || arr[ll][rr][cc] == 'E') && visited[ll][rr][cc] != 1) {
						visited[ll][rr][cc] = 1;
						q.push({ ll,rr,cc,cnt + 1 });
					}
				}
			}
		}

		if (ans == 0) {
			printf("Trapped!\n");
		}
		else {
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
}
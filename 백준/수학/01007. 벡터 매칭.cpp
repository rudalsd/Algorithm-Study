#include <iostream>
#include<cmath>

using namespace std;

struct vect {
	double y;
	double x;
};

int N;

vect pos[21];													//각각의 좌표를 저장할 배열
double y;
double x;
int p = 0;														//플러스의 개수 저장
int m = 0;														//마이너스의 개수 저장
double ans;

void dfs(int level)												//시작점과 끝점이 반반이므로 반은 플러스 반은 마이너스 값을 가짐
{
	int flag = 0;
	if (level == N) {
		double d = sqrt(y * y + x * x);							//길이 d에 저장
		if (ans > d) {
			ans = d;
		}
		return;
	}

	else {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				if (p == N / 2) {								//플러스 개수가 다 찼다면
					y -= pos[level].y;
					x -= pos[level].x;
					m++;
					flag = 1;
				}
				else {
					y += pos[level].y;
					x += pos[level].x;
					p++;
				}
			}
			if (i == 1) {
				if (m == N / 2) {								//마이너스 개수가 다 찼다면
					y += pos[level].y;
					x += pos[level].x;
					p++;
				}
				else {
					y -= pos[level].y;
					x -= pos[level].x;
					m++;
					flag = 1;
				}
			}
			dfs(level + 1);
			if (flag == 1) {
				y += pos[level].y;
				x += pos[level].x;
				m--;
			}
			else {
				y -= pos[level].y;
				x -= pos[level].x;
				p--;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		ans = 987654321;

		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &pos[i].y, &pos[i].x);
		}

		dfs(0);

		printf("%0.8lf\n", ans);
	}
}
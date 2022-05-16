#include <iostream>
#include<cmath>

using namespace std;

struct vect {
	double y;
	double x;
};

int N;

vect pos[21];													//������ ��ǥ�� ������ �迭
double y;
double x;
int p = 0;														//�÷����� ���� ����
int m = 0;														//���̳ʽ��� ���� ����
double ans;

void dfs(int level)												//�������� ������ �ݹ��̹Ƿ� ���� �÷��� ���� ���̳ʽ� ���� ����
{
	int flag = 0;
	if (level == N) {
		double d = sqrt(y * y + x * x);							//���� d�� ����
		if (ans > d) {
			ans = d;
		}
		return;
	}

	else {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				if (p == N / 2) {								//�÷��� ������ �� á�ٸ�
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
				if (m == N / 2) {								//���̳ʽ� ������ �� á�ٸ�
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
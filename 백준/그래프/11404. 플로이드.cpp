#include <iostream>

using namespace std;

int n, m;
long long cost[101][101];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {			//������� �������� ���� �� 0���� �ʱ�ȭ
		for (int j = 1; j <= n; j++) {		//�ƴ϶�� INF�� �ʱ�ȭ
			if (i == j) {
				cost[i][j] = 0;
			}
			else {
				cost[i][j] = 99999999999;
			}
		}
	}

	for (int i = 0; i < m; i++) {			//������� �������� ���� ������ �������� ��
		int a, b, c;						//���� ª�� �Ÿ��� �ʱ�ȭ
		scanf("%d %d %d", &a, &b, &c);
		if (cost[a][b] > c) {
			cost[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) {			//���İ��� ���
		for (int i = 1; i <= n; i++) {		//��� ���
			for (int j = 1; j <= n; j++) {	//���� ���
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == 99999999999) {	//�ѹ��� ������ ���� �ʾҴٸ�
				cout << 0 << " ";				//�� �� �����Ƿ� 0���
			}
			else {
				cout << cost[i][j] << " ";
			}
		}
		cout << endl;
	}
}
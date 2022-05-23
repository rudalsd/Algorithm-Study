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
shark arr[10001];					//�� ����� ������ ����� �迭
int dr[5] = { 0,-1,1,0,0 };			//���� �迭
int dc[5] = { 0,0,0,1,-1 };
int visited[101][101];				//�� ������ ��ҿ� �� �ִ��� üũ�ϱ� ���� �迭

int main()
{
	cin >> R >> C >> M;
	int idx = 1;
	int sum = 0;

	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		if (d < 3) {				//���� �ӵ� �̻��̸� ������ ���ڸ��� ���ƿ��� ������
			s %= 2 * (R - 1);		//�� (����-1)*2�� ���� ������ ���� �ӵ��� �־��ش�.
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
		for (int i = 1; i <= M; i++) {		//���� ����� ���� ��ġ�� �ִ� ��� ��
			if (arr[i].r == 0) continue;	//���� ���� ����� ����� ��ȣ�� x�� ����
			if (idx == arr[i].c) {
				if (min > arr[i].r) {
					min = arr[i].r;
					x = i;
				}
			}
		}
		if (x != 987654321) {				//x�� ��� �Ǿ��ٸ� �� �� ���ְ�
			sum += arr[x].z;				//sum�� ũ�⸦ �����ش�.
			arr[x] = { 0 };
		}

		for (int i = 1; i <= M; i++) {		//��� �� �����δ�.
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
			if (visited[rr][cc] == 0) {		//���� ó�� �� �����ߴٸ�
				visited[rr][cc] = i;		//visited�迭�� ��� ��ȣ�� ����
				arr[i].r = rr;
				arr[i].c = cc;
			}
			else {							//�̹� �� �ִ� �� �ִٸ�
				if (arr[i].z > arr[visited[rr][cc]].z) {
					arr[visited[rr][cc]] = { 0 };
					visited[rr][cc] = i;	//ũ�⸦ �� �� �� ũ��
					arr[i].r = rr;			//visited�迭�� ������ش�
					arr[i].c = cc;
				}
				else {
					arr[i] = { 0 };			//�� �۴ٸ� �� ���� �� ���ش�.
				}
			}
		}
		idx++;				//���������� �ű��.
	}

	cout << sum;		//��� ���
}
#include<iostream>
#include<deque>

using namespace std;

struct pos {
	int y;
	int x;
};

int N, K, L;
int arr[101][101];			//����
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dir = 1;
deque<pos> dq;
int cnt;
char direction[10001];		//�ð� X���� ������ ���� ������ �迭

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		direction[a] = b;
	}

	dq.push_back({ 1,1 });
	arr[1][1] = 2;

	while (1)
	{
		int fy = dq.front().y;	//�Ӹ�
		int fx = dq.front().x;
		int by = dq.back().y;	//����
		int bx = dq.back().x;

		int yy = fy + dy[dir];	//�̵��� ��ǥ
		int xx = fx + dx[dir];

		cnt++;

		if (arr[yy][xx] == 2 || yy<1 || yy>N || xx<1 || xx>N) {	//�����̰ų� ���̶��
			printf("%d", cnt);
			return 0;
		}

		if (arr[yy][xx] != 1) {	//����� ���� ������
			arr[by][bx] = 0;
			dq.pop_back();
		}

		arr[yy][xx] = 2;
		dq.push_front({ yy,xx });

		if (direction[cnt] == 'L') {
			dir--;
		}
		else if (direction[cnt] == 'D') {
			dir++;
		}

		if (dir < 0) {
			dir = 3;
		}
		if (dir > 3) {
			dir = 0;
		}
	}
}
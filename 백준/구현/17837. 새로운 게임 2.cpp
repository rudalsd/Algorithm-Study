#include<iostream>
#include<vector>

using namespace std;

struct piece {
	int y;
	int x;
	int dir;
};

int N, K;
int m[13][13];
vector<int> cur[13][13];
piece arr[11];
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

vector<int> change(vector<int> vect)	//���������� �̵����� ���
{
	for (int i = 0; i < vect.size() / 2; i++) {
		int temp = vect[i];
		vect[i] = vect[vect.size() - 1 - i];
		vect[vect.size() - 1 - i] = temp;
	}

	return vect;
}

void move(int num)		//���� �̵�
{
	vector<int> temp;
	vector<int> remain;
	int y = arr[num].y;
	int x = arr[num].x;
	int dir = arr[num].dir;

	bool flag = false;

	for (int i = 0; i < cur[y][x].size(); i++) {
		if (cur[y][x][i] == num) {
			flag = true;
		}
		if (flag == true) {
			temp.push_back(cur[y][x][i]);	//�Բ� ������ ��
		}
		else {
			remain.push_back(cur[y][x][i]);	//���� �ִ� ��
		}
	}

	int yy = y + dy[dir];
	int xx = x + dx[dir];

	if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
		if (m[yy][xx] == 0) {	//��� ĭ
			for (auto next : temp) {
				cur[yy][xx].push_back(next);
				arr[next] = { yy,xx,arr[next].dir };
			}
			cur[y][x] = remain;
		}
		else if (m[yy][xx] == 1) {	//������ ĭ
			temp = change(temp);
			for (auto next : temp) {
				cur[yy][xx].push_back(next);
				arr[next] = { yy,xx,arr[next].dir };
			}
			cur[y][x] = remain;
		}
		else {	//�Ķ��� ĭ
			if (dir % 2 == 0) {
				dir--;
			}
			else {
				dir++;
			}
			yy = y + dy[dir];
			xx = x + dx[dir];
			if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
				if (m[yy][xx] == 0) {	//��� ĭ
					for (auto next : temp) {
						cur[yy][xx].push_back(next);
						if (next == num) {
							arr[next] = { yy,xx,dir };
						}
						else {
							arr[next] = { yy,xx,arr[next].dir };
						}
					}
					cur[y][x] = remain;
				}
				else if (m[yy][xx] == 1) {	//������ ĭ
					temp = change(temp);
					for (auto next : temp) {
						cur[yy][xx].push_back(next);
						if (next == num) {
							arr[next] = { yy,xx,dir };
						}
						else {
							arr[next] = { yy,xx,arr[next].dir };
						}
					}
					cur[y][x] = remain;
				}
				else {	//�Ķ��� ĭ
					arr[num] = { y,x,dir };
				}
			}
			else {	//����� ���
				arr[num] = { y,x,dir };
			}
		}
	}
	else {	//����� ���
		if (dir % 2 == 0) {
			dir--;
		}
		else {
			dir++;
		}
		yy = y + dy[dir];
		xx = x + dx[dir];
		if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
			if (m[yy][xx] == 0) {	//��� ĭ
				for (auto next : temp) {
					cur[yy][xx].push_back(next);
					if (next == num) {
						arr[next] = { yy,xx,dir };
					}
					else {
						arr[next] = { yy,xx,arr[next].dir };
					}
				}
				cur[y][x] = remain;
			}
			else if (m[yy][xx] == 1) {	//������ ĭ
				temp = change(temp);
				for (auto next : temp) {
					cur[yy][xx].push_back(next);
					if (next == num) {
						arr[next] = { yy,xx,dir };
					}
					else {
						arr[next] = { yy,xx,arr[next].dir };
					}
				}
				cur[y][x] = remain;
			}
			else {	//�Ķ��� ĭ
				arr[num] = { y,x,dir };
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	for (int i = 1; i <= K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cur[a][b].push_back(i);
		arr[i] = { a,b,c };
	}

	int cnt = 0;

	while (1) {
		cnt++;
		for (int i = 1; i <= K; i++) {
			move(i);	//������ �̵�
			for (int i = 1; i <= N; i++) {	//���� 4���� �����ִ��� Ȯ��
				for (int j = 1; j <= N; j++) {
					if (cur[i][j].size() >= 4) {
						printf("%d", cnt);
						return 0;
					}
				}
			}
		}

		if (cnt > 1000) {	//1000���� ���� ���
			printf("%d", -1);
			return 0;
		}
	}
}
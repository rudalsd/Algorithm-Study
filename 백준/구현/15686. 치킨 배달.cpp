#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos {			//�� ��ǥ�� �����ϱ� ���� pos struct
	int y;
	int x;
};

int N, M;
int arr[50][50];		//��
vector<pos> chicken;	//ġŲ���� ��ǥ�� ������ vector
pos box[13];			//������ ������ �迪
int sum;
int ans = 987654321;

void dfs(int level, int num)
{
	if (level == M)
	{
		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					int min = 987654321;
					for (int k = 0; k < M; k++) {
						int y = box[k].y;		//�������� ���� ġŲ���� ��ǥ�� ����
						int x = box[k].x;		//�Ÿ��� ��� �� dist�� ����
						int dist = abs(y - i) + abs(x - j);
						if (min > dist) {		//���� ���� dist�� min�� ����
							min = dist;
						}
					}
					sum += min;			//sum�� min�� ����
				}
			}
		}
		if (ans > sum) {			//���� ���� sum�� ans�� ���
			ans = sum;
		}
		return;
	}

	for (int i = num; i < chicken.size() - M + 1 + level; i++) {
		box[level] = chicken[i];
		dfs(level + 1, i + 1);
		box[level] = { 0,0 };
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {	//ġŲ������ chicken vector�� push
				chicken.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);

	cout << ans;
}
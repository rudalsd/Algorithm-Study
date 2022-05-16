#include <iostream>
#include <string>

using namespace std;

int N, M;
int arr[4][4];													//���� ����
int visited[4][4];												//0�� �� ����, 1�� �� ����
int ans;
int sum;

void dfs(int y, int x) {
	if (x == M) {												//�� �� �Է��� ������ ���� �ٷ� �̵�
		y += 1;
		x = 0;
	}
	if (y == N) {												//������ ĭ���� �Է��� ������ ���
		sum = 0;
		int temp = 0;
		for (int i = 0; i < N; i++) {							//���κ��� ���
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 0) {						//visited[i][j] == 0�̸� 
					temp = temp * 10 + arr[i][j];				//temp*10 + arr[i][j]�� temp�� ����
				}
				else {											//�ƴ϶��
					sum += temp;								//���ݱ��� ���� temp���� sum�� ���ϰ�
					temp = 0;									//temp �ʱ�ȭ
				}
			}
			sum += temp;										//������ ���� sum�� ���ϰ�
			temp = 0;											//temp �ʱ�ȭ
		}
		for (int i = 0; i < M; i++) {							//���� ���
			for (int j = 0; j < N; j++) {
				if (visited[j][i] == 1) {
					temp = temp * 10 + arr[j][i];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
			temp = 0;
		}

		if (ans < sum) {										//sum�� ���� ans���� �� ũ�ٸ� ans�� sum���� ����
			ans = sum;
		}

		return;
	}

	visited[y][x] = 0;
	dfs(y, x + 1);

	visited[y][x] = 1;
	dfs(y, x + 1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	dfs(0, 0);

	cout << ans;
}
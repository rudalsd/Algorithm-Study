#include <iostream>
#include <cstring>

using namespace std;

int arr[100001];
int visited[100001];											//�湮�� üũ�� �迭
int isTeam[100001];												//���� �������� üũ�� �迭
int flag = 0;													//���� �������� �Ұ������� ����� flag ����
int cnt = 0;

void dfs(int cur)
{
	if (arr[cur] == cur) {										//������ �����ߴٸ�
		isTeam[cur] = 1;										//������ �� ���� �迭 1�� ����
		flag = -1;												//��Ʈ��ŷ���� ���� ������ ����� ������ isTeam -1�� �ٲٱ� ����
		return;
	}
	if (isTeam[cur] == -1) {									//���� �Ұ����ϴٸ�
		flag = -1;												//��Ʈ��ŷ���� ���� ������ ����� ������ isTeam -1�� �ٲٱ� ����
		return;
	}
	if (visited[cur] != 1) {									//�湮���� �ʾҴٸ�
		visited[cur] = 1;										//�湮 üũ ��
		dfs(arr[cur]);											//dfs
		visited[cur] = 0;										//���� ���� visited�迭 �ʱ�ȭ
		if (flag == -1) {										//flag�� -1�̶��
			isTeam[cur] = -1;									//���� �Ұ����ϹǷ� isTeam = -1
			cnt++;
		}
		else {													//�ƴ϶�� ���� �����ϹǷ�
			isTeam[cur] = 1;									//isTeam = 1
		}
		if (flag == cur) {										//���� ��Ʈ��ŷ �� �ϳ��� ����Ŭ�� �ϼ��ȴٸ� �������� ���� �Ұ����ϹǷ�
			flag = -1;											//flag = -1
		}
	}
	else {														//���� �湮�� ���� �ѹ� �� �湮�Ѵٸ�
		flag = cur;												//flag�� cur�� �ٲ���
		return;
	}
}

int main()
{
	int T;
	cin >> T;
	int n;

	for (int t = 0; t < T; t++) {
		cin >> n;
		cnt = 0;
		memset(isTeam, 0, 4 * (n + 1));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= n; i++) {
			flag = 0;
			if (isTeam[i] == 0) {
				dfs(i);
			}
		}

		cout << cnt << endl;;
	}
}
#include<iostream>

using namespace std;

int N;
int arr[51][10];
int order[10];
int visited[10];
int ans;

int getScore()		//�߱� ����
{
	int cur = 1;
	int score = 0;
	for (int i = 1; i <= N; i++) { //�̴� ��ȣ
		int out = 0;
		int base[4] = { 0 };

		while (out < 3) {	//outī��Ʈ�� 3�� �� ������
			int player = order[cur];
			base[0] = 1;
			if (arr[i][player] == 0) {	//�ƿ�
				out++;
			}
			else {	//����
				for (int j = 3; j >= 0; j--) {
					if (base[j] == 0) {
						continue;
					}
					else {
						if (j + arr[i][player] > 3) {
							score++;
						}
						else {
							base[j + arr[i][player]] = 1;
						}
						base[j] = 0;
					}
				}
			}

			cur++;
			if (cur > 9) cur = 1;
		}
	}

	return score;
}

void dfs(int level)
{
	if (level == 5 && order[4] != 1) {	//4�� Ÿ�ڰ� 1�� ����� �ƴ϶��
		return;
	}
	if (level == 10) {
		ans = max(ans, getScore());
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			order[level] = i;
			dfs(level + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(1);

	printf("%d", ans);
}
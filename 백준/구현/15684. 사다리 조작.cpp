#include<iostream>

using namespace std;

int N, M, H;
int arr[30][11];
int cnt;
bool cur;

bool check()	//i�� ���μ��� ����� i���� �ƴϸ� false return
{
	for (int i = 0; i < N; i++) {
		int temp = i;
		for (int j = 0; j < H; j++) {
			if (arr[j][temp] == 1) {
				temp--;
			}
			else if (arr[j][temp + 1] == 1) {
				temp++;
			}
		}
		if (temp != i) return false;
	}

	return true;
}

void dfs(int limit, int num)
{
	if (cur == true) return;
	if (cnt == limit) {	//���� ������ limit�̶�� check
		if (check()) {
			cur = true;
		}
		return;
	}

	for (int i = num; i < (N - 1) * H; i++) {
		int y = i / (N - 1);
		int x = i % (N - 1);
		x += 1;
		if (arr[y][x] == 0 && arr[y][x + 1] != 1 && arr[y][x - 1] != 1) {	//��ٸ��� ���� �� �ִٸ�
			arr[y][x] = 1;	//��ٸ� ��ġ
			cnt++;
			dfs(limit, i + 1);
			cnt--;
			arr[y][x] = 0;
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a - 1][b] = 1;
	}

	for (int i = 0; i < 4; i++) {	//���μ��� ���� 0 ~ 3
		cur = false;
		dfs(i, 0);
		if (cur == true) {
			printf("%d", i);
			return 0;
		}
	}

	printf("%d", -1);
}
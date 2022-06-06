#include <iostream>

using namespace std;

int N;
int qx[15];		//���� x��ǥ ����
int up[30];		//���� ������ �� �밢�� ���� üũ
int down[30];	//���� ������ �Ʒ� �밢�� ���� üũ
int cnt;
int ans;

int check(int y, int x)	//y,x ��ǥ�� ���� ���� �� �ִ��� üũ�ϴ� �Լ�
{
	if (qx[x] || up[y + x] || down[y - x + N - 1]) {
		return 0;		//���� �� ���ٸ� 0 return
	}

	return 1;			//���� �� �ִٸ� 1 return
}

void dfs(int y)			//�� �ٿ� �ϳ��� ���� �� �� �����Ƿ� 
{						//���� ������ �ٷ� y+1������ dfs ����
	if (cnt == N) {
		ans++;
		return;
	}
	if (y >= N) {
		return;
	}

	for (int x = 0; x < N; x++) {
		if (check(y, x))
		{
			qx[x]++;		//x��ǥ ����
			up[y + x]++;	//�밢�� ���� ����
			down[y - x + N - 1]++;
			cnt++;
			dfs(y + 1);
			cnt--;
			qx[x]--;
			up[y + x]--;
			down[y - x + N - 1]--;
		}
	}
}

int main()
{
	cin >> N;

	dfs(0);

	cout << ans;
}
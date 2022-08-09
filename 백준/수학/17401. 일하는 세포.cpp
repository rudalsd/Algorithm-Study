#include<iostream>
#include<vector>
#include<unordered_map>

#define ll long long
#define M 1000000007

using namespace std;

int T, N, D;

vector<vector<int>> all(21, vector<int>(21, 0));	//��� ����� ���� ���
unordered_map<int, vector<vector<int>>> m;		//�޸����̼�

vector<vector<int>> matrix(vector<vector<int>> arr1, vector<vector<int>> arr2)	//��� ��
{
	vector<vector<int>> ret(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ll sum = 0;
			for (int k = 1; k <= N; k++) {
				sum += (((ll)arr1[i][k] % M) * ((ll)arr2[k][j] % M)) % M;
				sum %= M;
			}
			ret[i][j] = sum % M;
		}
	}

	return ret;
}

vector<vector<int>> conquer(int num)		//���� ����
{
	if (num == 1) {
		return all;
	}
	if (!m[num].empty()) {
		return m[num];
	}

	if (num % 2 == 0) {
		return m[num] = matrix(conquer(num / 2), conquer(num / 2));
	}
	else {
		return m[num] = matrix(conquer(num - 1), conquer(1));
	}
}

int main()
{
	scanf("%d %d %d", &T, &N, &D);

	vector<vector<int>> remain(N + 1, vector<int>(N + 1, 0));	//������ ��ĵ��� ��
	vector<vector<int>> ans(N + 1, vector<int>(N + 1, 0));		//��

	for (int i = 1; i <= N; i++) {	//���� ��ķ� �ʱ�ȭ
		all[i][i] = 1;
		ans[i][i] = 1;
	}

	int d = D % T;	//���� ��ĵ��� ��

	for (int i = 0; i < T; i++) {
		int m, a, b, c;
		scanf("%d", &m);
		vector<vector<int>> temp(N + 1, vector<int>(N + 1, 0));

		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b, &c);
			temp[a][b] = c;	//i�� ° ���
		}
		if (i == d) {	//������ ���
			remain = all;
		}
		all = matrix(all, temp);
	}

	if (D / T != 0) {	//��� ��ĵ��� ������ ����� �������� Ƚ��
		ans = conquer(D / T);

	}

	ans = matrix(ans, remain);


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
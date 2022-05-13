#include <iostream>
#include <cstring>

using namespace std;

int arr[100005];															//ȭ��ǥ ����
int dp[100005][5][5];														//����, �޹� ��ġ, ������ ��ġ
int N;

int cost[5][5] = {															//��� �迭
	0,2,2,2,2,
	2,1,3,4,3,
	2,3,1,3,4,
	2,4,3,1,3,
	2,3,4,3,1,
};

int DP(int num, int left, int right)
{
	if (num == N) return 0;													//������ ������ return 0
	if ((left != 0 && right != 0) && left == right) return 987654321;		//���� �� ���� ����̹Ƿ� return 987654321

	int& cur = dp[num][left][right];
	if (cur != -1) return cur;												//�̹� �鷶�ٸ� return cur

	return cur = min(DP(num + 1, arr[num + 1], right) + cost[left][arr[num + 1]], DP(num + 1, left, arr[num + 1]) + cost[right][arr[num + 1]]);
	//�޹��� �Ű��� ���� �������� �Ű��� �� ������ ���ؼ� �� ���� ������ dp�迭�� �ֱ�
}

int main()
{
	for (int i = 1; i <= 100001; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 0) {
			N = i - 1;
			break;
		}
	}

	memset(dp, -1, sizeof(dp));

	int ans = DP(0, 0, 0);

	cout << ans;
}
#include<iostream>
#include<cmath>

using namespace std;

struct acc {		//����� ��ġ struct
	int y;
	int x;
};

int N, W;

acc arr[1001];		//����� ��ġ�� ������ �迭
int dp[1001][1001];	//dp[a][b] a�� 1�� �ڵ���, b�� 2�� �ڵ����� ���� ��� ��ġ

int dist(acc a, acc b)		//a���� b���� �Ÿ� return
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int dfs(int a, int b)
{
	if (a == W || b == W) return 0;	//������ ����̶��
	if (dp[a][b] != 0) return dp[a][b];	//�ѹ��̶� ����Ǿ��ٸ�

	int nAcc = max(a, b) + 1;	//���� ��� ��ȣ
	int dist1, dist2;

	if (a == 0) {		//1�� �ڵ����� �������� ���� �Ÿ�
		dist1 = dist(arr[nAcc], { 1,1 });
	}
	else {
		dist1 = dist(arr[nAcc], arr[a]);
	}
	if (b == 0) {		//2�� �ڵ����� �������� ���� �Ÿ�
		dist2 = dist(arr[nAcc], { N,N });
	}
	else {
		dist2 = dist(arr[nAcc], arr[b]);
	}

	return dp[a][b] = min(dist1 + dfs(nAcc, b), dist2 + dfs(a, nAcc));
}

void route(int a, int b)
{
	if (a == W || b == W) return;

	int nAcc = max(a, b) + 1;
	int dist1, dist2;

	if (a == 0) {
		dist1 = dist(arr[nAcc], { 1,1 });
	}
	else {
		dist1 = dist(arr[nAcc], arr[a]);
	}
	if (b == 0) {
		dist2 = dist(arr[nAcc], { N,N });
	}
	else {
		dist2 = dist(arr[nAcc], arr[b]);
	}

	if (dp[nAcc][b] + dist1 < dp[a][nAcc] + dist2) {
		printf("1\n");		//1�� �ڵ����� �����̴� �� ���� ª�� �Ÿ��� ��
		route(nAcc, b);
	}
	else {					//2�� �ڵ����� �����̴� �� ���� ª�� �Ÿ��� ��
		printf("2\n");
		route(a, nAcc);
	}

}

int main()
{
	cin >> N >> W;

	for (int i = 1; i <= W; i++) {
		scanf("%d %d", &arr[i].y, &arr[i].x);
	}

	printf("%d\n", dfs(0, 0));
	route(0, 0);
}
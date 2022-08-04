#include<iostream>

using namespace std;

int w, n;
int arr[5000];
int dp[400001];
int dp2[400001];


int main()
{
	scanf("%d %d", &w, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int weight = arr[i] + arr[j];	//���� 2���� ���� ������ dp�� idx�� �Բ� ����
			if (dp[weight] == 0) {
				dp[weight] = i;
				dp2[weight] = j;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int weight = w - arr[i] - arr[j];
			if (weight > 400000 || weight < 0) continue;	//�Ұ����� ���
			if (dp[weight] == i || dp2[weight] == j || dp[weight] == j || dp2[weight] == i || dp[weight] == 0) continue;	//idx�� ��ġ�� ���
			printf("YES");	//���� ������ �ƴ϶�� YES ���
			return 0;
		}
	}

	printf("NO");	//�Ұ����ϴٸ� NO ���
}
#include<iostream>

using namespace std;

int N, K;
int arr[201];
int robot[101];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= 2 * N; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = 0;

	while (1) {
		ans++;
		int temp = arr[2 * N];

		for (int i = 2 * N; i > 0; i--) {	//��Ʈ �ű��
			arr[i] = arr[i - 1];
		}
		for (int i = N; i > 0; i--) {	//��Ʈ�� ���� �κ� �ű��
			robot[i] = robot[i - 1];
		}
		robot[1] = 0;
		arr[1] = temp;

		robot[N] = 0;
		for (int i = N - 1; i > 0; i--) {	//�κ� ������ �����̱�
			if (robot[i] == 1) {
				if (arr[i + 1] > 0 && robot[i + 1] != 1) {
					robot[i + 1] = 1;
					robot[i] = 0;
					arr[i + 1]--;
				}
			}
		}

		if (arr[1] != 0) {	//�ø��� ��ġ�� �κ� �ø���
			arr[1]--;
			robot[1] = 1;
		}

		int cnt = 0;
		for (int i = 1; i <= 2 * N; i++) {	//������ 0�� ĭ ����
			if (arr[i] == 0) cnt++;
		}

		if (cnt >= K) {
			printf("%d", ans);
			return 0;
		}
	}
}
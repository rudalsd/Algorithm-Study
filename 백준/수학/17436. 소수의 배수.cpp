#include<iostream>
#include<vector>

using namespace std;

int N;
long long M;
int arr[10];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	long long ans = 0;

	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		long long num = 1;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cnt++;		//�� ���� �Ҽ��� ������ �ִ���
				num *= arr[j];	//�Ҽ����� ����
			}
		}

		if (cnt % 2 == 1) {
			ans += M / num;		//M�� �Ҽ����� ��� ���� ������ ���� ���� ����
		}
		else {
			ans -= M / num;		//M�� �Ҽ����� ��� ���� ������ ���� ���� ��
		}
	}

	cout << ans;
}
#include<iostream>

using namespace std;

int arr[110010];						//����� �� ������ �迭
int coin[110];							//������ ���� ���� �迭

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	arr[0] = 1;

	for (int i = 0; i < n; i++) {					//�ߺ��� �����ϱ� ���ؼ� n���� ������ k���� ������
		for (int j = 0; j < k; j++) {
			arr[j + coin[i]] += arr[j];				//j + coin[i]��° �迭�� ���� j��° ���� ���ϱ�(����� �� �ջ�)
		}
	}

	printf("%d", arr[k]);
}
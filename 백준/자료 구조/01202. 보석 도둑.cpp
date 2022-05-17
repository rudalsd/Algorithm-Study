#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

struct jewelry {
	int M;
	long long V;
};

int bag[300001];																//������ ���Ը� ������ �迭
jewelry arr[300001];															//������ ���Կ� ��ġ�� ������ �迭

bool cmp(jewelry left, jewelry right)
{
	return left.M < right.M;													//������ �������
}

int main()
{
	cin >> N >> K;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int M;
		long long V;															//���Կ� ��ġ�� �Է¹޾� pq�� push
		scanf("%d %lld", &arr[i].M, &arr[i].V);
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &bag[i]);
	}

	sort(bag, bag + K);															//���� ���԰� ������ ������� ����
	sort(arr, arr + N, cmp);													//���� ���԰� ������ ������� ����

	long long sum = 0;
	int cnt = 0;

	for (int i = 0; i < K; i++) {
		while (cnt < N && arr[cnt].M <= bag[i]) {								//���濡 �� �� �ִ� ��� �������� pq�� ����
			pq.push(arr[cnt].V);
			cnt++;
		}

		if (!pq.empty()) {														//���� ������ �ִٸ�
			sum += pq.top();													//���濡 �ְ� sum�� ���� ��� ���� �ֱ�
			pq.pop();
		}
	}

	cout << sum;
}
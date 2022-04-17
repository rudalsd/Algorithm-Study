#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> pq;			//min heap ����


	for (int i = 0; i < N; i++) {							//priority_queue�� �Է� ���� ���� �ֱ�
		int num;
		cin >> num;
		pq.push(num);
	}

	int sum = 0;

	while (pq.size() > 1) {									//������ �� ���ڸ� ���� �� ���� �ݺ�
		int num1 = pq.top();								//���� ���� ��
		pq.pop();
		int num2 = pq.top();								//�ι�°�� ���� ��
		pq.pop();

		sum += num1 + num2;									//���� ���� ����

		pq.push(num1 + num2);								//�� ���� ���� �� pq�� �ٽ� ����
	}

	cout << sum;
}
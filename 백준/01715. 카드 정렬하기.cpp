#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> pq;			//min heap 생성


	for (int i = 0; i < N; i++) {							//priority_queue에 입력 받은 숫자 넣기
		int num;
		cin >> num;
		pq.push(num);
	}

	int sum = 0;

	while (pq.size() > 1) {									//마지막 한 숫자만 남을 때 까지 반복
		int num1 = pq.top();								//제일 작은 수
		pq.pop();
		int num2 = pq.top();								//두번째로 작은 수
		pq.pop();

		sum += num1 + num2;									//최종 값에 저장

		pq.push(num1 + num2);								//두 수를 더한 값 pq에 다시 넣음
	}

	cout << sum;
}
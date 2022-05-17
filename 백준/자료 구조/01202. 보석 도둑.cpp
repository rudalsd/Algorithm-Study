#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

struct jewelry {
	int M;
	long long V;
};

int bag[300001];																//가방의 무게를 저장할 배열
jewelry arr[300001];															//보석의 무게와 가치를 저장할 배열

bool cmp(jewelry left, jewelry right)
{
	return left.M < right.M;													//가벼운 순서대로
}

int main()
{
	cin >> N >> K;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int M;
		long long V;															//무게와 가치를 입력받아 pq에 push
		scanf("%d %lld", &arr[i].M, &arr[i].V);
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &bag[i]);
	}

	sort(bag, bag + K);															//가방 무게가 가벼운 순서대로 정렬
	sort(arr, arr + N, cmp);													//보석 무게가 가벼운 순서대로 정렬

	long long sum = 0;
	int cnt = 0;

	for (int i = 0; i < K; i++) {
		while (cnt < N && arr[cnt].M <= bag[i]) {								//가방에 들어갈 수 있는 모든 보석들을 pq에 저장
			pq.push(arr[cnt].V);
			cnt++;
		}

		if (!pq.empty()) {														//남은 보석이 있다면
			sum += pq.top();													//가방에 넣고 sum에 가장 비싼 보석 넣기
			pq.pop();
		}
	}

	cout << sum;
}
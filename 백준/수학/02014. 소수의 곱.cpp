#include<iostream>
#include<queue>

using namespace std;

int arr[100];

int main()
{
	int K, N;
	cin >> K >> N;

	priority_queue<long long, vector<long long>, greater<>> pq;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	long long result = 0;

	for (int i = 0; i < N; i++) {
		result = pq.top();
		pq.pop();
		for (int j = 0; j < K; j++) {
			if (result * arr[j] > 0)
				pq.push(result * arr[j]);

			if (result % arr[j] == 0) {
				break;
			}
		}
	}

	cout << result;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, K;
vector<int> arr;
int ans[300000];

int main()
{
	priority_queue<pair<int, int>>pq;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; i++) {
		int c;
		scanf("%d", &c);

		pq.push({ c,i });
	}

	if (pq.top().first > (N + 1) / 2) {
		printf("-1");
		return 0;
	}

	while (!pq.empty()) {
		const int cnt = pq.top().first;
		const int num = pq.top().second;
		pq.pop();

		for (int i = 0; i < cnt; i++) {
			arr.push_back(num);
		}
	}

	int num = 0;

	for (int i = 0; i < (N + 1) / 2; i++) {
		ans[num] = arr[i];
		num += 2;
	}

	num = 1;

	for (int i = (N + 1) / 2; i < N; i++) {
		ans[num] = arr[i];
		num += 2;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", ans[i]);
	}
}
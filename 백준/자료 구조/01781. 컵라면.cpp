#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int ans;

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> arr;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr.push_back({ a,b });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		pq.push(arr[i].second);
		
		if (arr[i].first < pq.size()) {
			pq.pop();
		}
	}

	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	printf("%d", ans);
}
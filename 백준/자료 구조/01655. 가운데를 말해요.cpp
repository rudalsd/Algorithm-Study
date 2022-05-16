#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> minpq;
	priority_queue<int, vector<int>, greater<>> maxpq;
	int mid;

	int N;
	cin >> N;

	minpq.push(-999999);
	maxpq.push(999999);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i == 0) {
			mid = tmp;
		}
		else {
			if (mid >= tmp) {
				if (minpq.size() >= maxpq.size()) {
					if (minpq.top() <= tmp) {
						maxpq.push(mid);
						mid = tmp;
					}
					else {
						minpq.push(tmp);
						tmp = minpq.top();
						minpq.pop();
						maxpq.push(mid);
						mid = tmp;
					}
				}
				else {
					minpq.push(tmp);
				}
			}
			else {
				if (minpq.size() >= maxpq.size()) {
					maxpq.push(tmp);
				}
				else {
					if (minpq.top() >= tmp) {
						minpq.push(mid);
						mid = tmp;
					}
					else {
						minpq.push(mid);
						maxpq.push(tmp);
						tmp = maxpq.top();
						maxpq.pop();
						mid = tmp;
					}
				}
			}
		}
		printf("%d\n", mid);
	}
}
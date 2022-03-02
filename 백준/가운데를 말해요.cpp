#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> max;
	priority_queue<int> min;
	int mid;
	max.push(11111);
	min.push(-11111);

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		if (i == 0) {
			mid = num;
		}
		else {
			if (num > mid) {
				if (max.top() < num) {
					if (max.size() > min.size()) {
						min.push(mid);
						mid = max.top();
						max.pop();
						max.push(num);
					}
					else {
						max.push(num);
					}
				}
				else {
					if (max.size() > min.size()) {
						min.push(mid);
						mid = num;
					}
					else {
						max.push(num);
					}
				}
			}
			else if (num < mid) {
				if (min.top() > num) {
					if (max.size() <= min.size()) {
						max.push(mid);
						mid = min.top();
						min.pop();
						min.push(num);
					}
					else {
						min.push(num);
					}
				}
				else {
					if (max.size() <= min.size()) {
						max.push(mid);
						mid = num;
					}
					else {
						min.push(num);
					}
				}
			}
			else {
				if (max.size() > min.size()) {
					min.push(num);
				}
				else {
					max.push(num);
				}
			}
		}
		printf("%d\n", mid);
	}
}
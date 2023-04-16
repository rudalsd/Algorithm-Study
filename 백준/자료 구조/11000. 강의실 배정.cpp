#include<iostream>
#include<queue>

using namespace std;

int N;

struct Class {
	char cur;
	int time;
};

struct cmp {
	bool operator()(Class right, Class left) {
		if (right.time == left.time) {
			if (left.cur == 'e') {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return left.time < right.time;
		}
	}
};

int main()
{
	priority_queue<Class, vector<Class>, cmp> pq;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int S, T;
		scanf("%d %d", &S, &T);

		pq.push({ 's', S});
		pq.push({ 'e', T});
	}

	int ans = 0;
	int temp = 0;

	while (!pq.empty()) {
		const char cur = pq.top().cur;
		pq.pop();

		if (cur == 's') temp++;
		else temp--;

		ans = max(ans, temp);
	}

	printf("%d", ans);
}
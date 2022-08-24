#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

struct node {
	int num;
	int absolute;
};

struct cmp {
	bool operator()(node right, node left) {
		if (right.absolute == left.absolute) return left.num < right.num;
		return left.absolute < right.absolute;
	}
};

int main()
{
	priority_queue<node, vector<node>, cmp> pq;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x != 0) {
			pq.push({ x,abs(x) });
		}
		else {
			if (!pq.empty()) {
				printf("%d\n", pq.top().num);
				pq.pop();
			}
			else {
				printf("%d\n", 0);
			}
		}
	}
}
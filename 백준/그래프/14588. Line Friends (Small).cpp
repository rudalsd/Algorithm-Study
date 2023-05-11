#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int num;
	int pos;
	char cur;
};

struct cmp {
	bool operator()(node right, node left) {
		if (left.pos == right.pos) {
			if (left.cur == 'L') return true;
			else false;
		}
		return left.pos < right.pos;
	}
};

int N, Q;
int arr[301][301];

int main()
{
	scanf("%d", &N);

	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		pq.push({ i,a,'L' });
		pq.push({ i,b,'R' });
	}

	vector<int> stat;

	while (!pq.empty()) {
		const int num = pq.top().num;
		const int pos = pq.top().pos;
		const char cur = pq.top().cur;
		pq.pop();

		if (cur == 'L') {
			for (int& next : stat) {
				arr[next][num] = 1;
				arr[num][next] = 1;
			}
			stat.push_back(num);
		}
		else {
			for (auto i = stat.begin(); i != stat.end();i++) {
				if (*i == num) {
					stat.erase(i);
					break;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][i] != 0 && arr[i][k] != 0) {
					if (arr[j][k] == 0) {
						arr[j][k] = arr[j][i] + arr[i][k];
					}
					else {
						arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
					}
				}
			}
		}
	}

	scanf("%d", &Q);

	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (arr[a][b] != 0) {
			printf("%d\n", arr[a][b]);
		}
		else {
			printf("-1\n");
		}
	}
}
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int N, K;
int visited[1000001][11];

struct node {
	vector<int> num;
	int cnt;
};

int getDigit(int num)
{
	int ret = 1;

	while (1) {
		if (num < pow(10, ret)) {
			return ret;
		}
		ret++;
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	vector<int> num;

	if (N < 10) {
		printf("%d", -1);
		return 0;
	}

	int digit = getDigit(N);

	num.resize(digit);

	for (int i = digit - 1; i >= 0; i--) {
		num[i] = N / pow(10, i);
		N %= (int)pow(10, i);
	}

	queue<node> q;

	q.push({ num,0 });

	int ans = -1;

	while (!q.empty()) {
		vector<int> cur = q.front().num;
		vector<int> a = q.front().num;
		int cnt = q.front().cnt;
		q.pop();
		int num = 0;

		if (cur[digit - 1] == 0) continue;
		if (cnt > K) continue;

		for (int i = 0; i < digit; i++) {
			num += cur[i] * pow(10, i);
		}

		if (visited[num][cnt] == 1) continue;
		visited[num][cnt] = 1;

		if (cnt == K) {
			ans = max(ans, num);
		}

		for (int i = 0; i < digit - 1; i++) {
			for (int j = i + 1; j < digit; j++) {
				if (i != j) {
					cur = a;
					int temp = cur[i];
					cur[i] = cur[j];
					cur[j] = temp;

					q.push({ cur,cnt + 1 });
				}
			}
		}
	}

	printf("%d", ans);
}
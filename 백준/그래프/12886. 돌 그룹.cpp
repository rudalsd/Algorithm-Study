#include<iostream>
#include<queue>
#include<map>

using namespace std;

int A, B, C;
int sum;
int visited[1501][1501];

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	sum = A + B + C;

	if (sum % 3 != 0) {
		printf("%d", 0);
		return 0;
	}

	queue<pair<int, int>> q;
	q.push({ A,B });
	visited[A][B] = 1;
	visited[B][A] = 1;

	while (!q.empty()) {
		int A = q.front().first;
		int B = q.front().second;
		int C = sum - A - B;
		q.pop();

		if (A == B && B == C) {
			printf("%d", 1);
			return 0;
		}

		int stone[3] = { A,B,C };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (stone[i] > stone[j]) {
					int AA = stone[i] - stone[j];
					int BB = stone[j] * 2;

					if (visited[AA][BB] != 1 && visited[BB][AA] != 1) {
						visited[AA][BB] = 1;
						visited[BB][AA] = 1;
						q.push({ AA,BB });
					}
				}
			}
		}
	}


	printf("%d", 0);
}
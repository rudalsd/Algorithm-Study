#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int num;
		scanf("%d", &num);

		int startx, starty;
		int endx, endy;
		pair<int, int> arr[101];
		int visited[100] = { 0 };

		scanf("%d %d", &startx, &starty);

		for (int i = 0; i < num; i++) {
			scanf("%d %d", &arr[i].second, &arr[i].first);
		}

		scanf("%d %d", &arr[num].second, &arr[num].first);

		queue<pair<int, int>> q;
		q.push({ starty, startx });

		bool flag = false;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == arr[num].first && x == arr[num].second) {
				printf("happy\n");
				flag = true;
			}

			for (int i = 0; i <= num; i++) {
				if (visited[i] != 1) {
					if (abs(arr[i].first - y) + abs(arr[i].second - x) <= 1000) {
						visited[i] = 1;
						q.push({ arr[i].first, arr[i].second });
					}

				}
			}
		}

		if (flag == false) {
			printf("sad\n");
		}
	}
}
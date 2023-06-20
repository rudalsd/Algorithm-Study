#include<iostream>
#include<queue>

using namespace std;

int N;
int SCV[61][61][61];
int hp[3];

struct node {
	int scv[3];
	int cnt;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> hp[i];
	}

	queue<node> q;

	SCV[hp[0]][hp[1]][hp[2]] = 0;
	q.push({ {hp[0],hp[1],hp[2]}, 0 });

	while (!q.empty()) {
		int scv1 = q.front().scv[0];
		int scv2 = q.front().scv[1];
		int scv3 = q.front().scv[2];
		const int cnt = q.front().cnt;
		q.pop();

		if (scv1 < 0) scv1 = 0;
		if (scv2 < 0) scv2 = 0;
		if (scv3 < 0) scv3 = 0;
		if (SCV[scv1][scv2][scv3] == 0) SCV[scv1][scv2][scv3] = 987654321;
		if (SCV[scv1][scv2][scv3] <= cnt) continue;
		SCV[scv1][scv2][scv3] = cnt;

		q.push({ {scv1 - 9,scv2 - 3,scv3 - 1}, cnt + 1 });
		q.push({ {scv1 - 9,scv2 - 1,scv3 - 3}, cnt + 1 });
		q.push({ {scv1 - 1,scv2 - 3,scv3 - 9}, cnt + 1 });
		q.push({ {scv1 - 3,scv2 - 1,scv3 - 9}, cnt + 1 });
		q.push({ {scv1 - 3,scv2 - 9,scv3 - 1}, cnt + 1 });
		q.push({ {scv1 - 1,scv2 - 9,scv3 - 3}, cnt + 1 });
	}

	cout << SCV[0][0][0];

}

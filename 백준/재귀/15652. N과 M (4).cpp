#include<iostream>

using namespace std;

int N, M;
int box[8];

void dfs(int level, int num)
{
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = num; i <= N; i++) {
		box[level] = i;
		dfs(level + 1, i);
	}
}

int main()
{
	cin >> N >> M;

	dfs(0, 1);
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int vect[100001];
int power[100001];
int visited[100001];
vector<int> ans;

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
	power[pa] += power[pb];
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
		power[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int X, Y;
		scanf("%d %d", &X, &Y);

		if (Find(X) != Find(Y)) {
			Union(X, Y);
		}
	}

	int C, H, K;
	scanf("%d %d %d", &C, &H, &K);
	int cnt = 0;

	if (K) {
		for (int i = 1; i <= N; i++) {
			int temp = Find(i);
			if ((Find(C) != temp) && (temp != Find(H))) {
				if (visited[temp] == 0) {
					visited[temp] = 1;
					ans.push_back({ power[temp] });
				}
			}
		}
	}

	sort(ans.begin(), ans.end(), greater<>());

	int temp = power[Find(C)];

	for (int i = 0; i < min((int)ans.size(), K); i++) {
		temp += ans[i];
	}
	printf("%d", temp);
}
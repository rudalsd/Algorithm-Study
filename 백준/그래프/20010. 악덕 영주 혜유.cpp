#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int a;
	int b;
	int c;
};

bool cmp(node left, node right)
{
	return left.c < right.c;
}

int N, K;
node arr[1000000];
int vect[1000];
vector<pair<int, int>> list[1000];
int visited[1000];
int Max;
int start;

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
}

void dfs(int n, int cost)
{
	if (cost > Max) {
		Max = cost;
		start = n;
	}

	for (auto& next : list[n]) {
		if (visited[next.first] != 1) {
			visited[next.first] = 1;
			dfs(next.first, cost + next.second);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
	}

	sort(arr, arr + K, cmp);

	int ans = 0;

	for (int i = 0; i < K; i++) {
		const int a = arr[i].a;
		const int b = arr[i].b;
		const int c = arr[i].c;

		if (Find(a) != Find(b)) {
			list[a].push_back({ b,c });
			list[b].push_back({ a,c });
			Union(a, b);
			ans += c;
		}
	}

	visited[0] = 1;
	dfs(0, 0);

	Max = 0;
	fill(visited, visited + N, 0);

	visited[start] = 1;
	dfs(start, 0);

	printf("%d\n%d", ans, Max);
}
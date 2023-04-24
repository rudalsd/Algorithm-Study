#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct edge {
	int num;
	int from;
	int to;
	int dist;
};

bool Greater(edge left, edge right)
{
	return left.dist < right.dist;
}

bool Less(edge left, edge right)
{
	return left.dist > right.dist;
}

int N, M;
edge Edge[500000];
vector<int> ans;
int visited[500000];
int vect[200001];

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

int main()
{
	scanf("%d %d", &N, &M);

	if (N > M) {
		printf("NO");
		return 0;
	}

	for (int i = 0; i < M; i++) {
		int U, V, C;
		scanf("%d %d %d", &U, &V, &C);
		Edge[i] = { i + 1,U,V,C };
	}

	sort(Edge, Edge + M, Greater);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		const int a = Edge[i].from;
		const int b = Edge[i].to;
		const int num = Edge[i].num;

		if (Find(a) != Find(b)) {
			Union(a, b);
			visited[num] = 1;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	int flag = false;

	for (int i = 0; i < M; i++) {
		const int num = Edge[i].num;
		if (visited[num] == 0) {
			ans.push_back(num);
			Union(Edge[i].from, Edge[i].to);
			break;
		}
	}

	for (int i = 0; i < M; i++) {
		const int a = Edge[i].from;
		const int b = Edge[i].to;
		const int num = Edge[i].num;

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans.push_back(num);
		}
	}

	printf("YES\n");
	for (int num : ans) {
		printf("%d ", num);
	}
}
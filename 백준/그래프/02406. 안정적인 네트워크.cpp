#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int u;
	int v;
	int c;
};

bool cmp(node left, node right)
{
	return left.c < right.c;
}

int n, m;
int vect[1001];
vector<node> arr;
vector<pair<int, int>> ans;

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
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		Union(x, y);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			scanf("%d", &cost);
			if (i < j && i != 1) {
				arr.push_back({ i,j,cost });
			}
		}
	}

	sort(arr.begin(), arr.end(), cmp);

	int cost = 0;

	for (auto& next : arr) {
		const int u = next.u;
		const int v = next.v;
		const int c = next.c;

		if (Find(u) != Find(v)) {
			Union(u, v);
			cost += c;
			ans.push_back({ u, v });
		}
	}

	printf("%d %d\n", cost, (int)ans.size());

	for (auto& next : ans) {
		printf("%d %d\n", next.first, next.second);
	}
}
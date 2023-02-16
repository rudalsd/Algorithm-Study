#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int x;
	int y;
	int z;
};

bool cmp(node left, node right)
{
	return left.z < right.z;
}

int m, n;
int vect[200000];

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
	while (1) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;

		int ans = 0;
		vector<node> arr;

		for (int i = 0; i < m; i++) {
			vect[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			arr.push_back({ x,y,z });
			ans += z;
		}

		sort(arr.begin(), arr.end(), cmp);

		for (auto& next : arr) {
			const int x = next.x;
			const int y = next.y;
			const int z = next.z;

			if (Find(x) != Find(y)) {
				Union(x, y);
				ans -= z;
			}
		}

		printf("%d\n", ans);
	}
}
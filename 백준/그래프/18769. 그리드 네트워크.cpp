#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int u, v, w;
};

bool cmp(node left, node right)
{
	return left.w < right.w;
}

int vect[250001];
vector<node> arr;

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int u, int v)
{
	int pu = Find(u);
	int pv = Find(v);

	vect[pv] = pu;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int R, C;
		scanf("%d %d", &R, &C);

		arr.clear();

		for (int i = 1; i <= R * C; i++) {
			vect[i] = i;
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C - 1; j++) {
				int num;
				scanf("%d", &num);

				arr.push_back({ (i - 1) * C + j, (i - 1) * C + j + 1,num });
			}
		}

		for (int i = 1; i <= R-1; i++) {
			for (int j = 1; j <= C; j++) {
				int num;
				scanf("%d", &num);

				arr.push_back({ (i - 1) * C + j, i * C + j,num });
			}
		}

		sort(arr.begin(), arr.end(), cmp);

		int ans = 0;

		for (auto& next : arr)
		{
			const int u = next.u;
			const int v = next.v;
			const int w = next.w;

			if (Find(u) != Find(v)) {
				Union(u, v);
				ans += w;
			}
		}

		printf("%d\n", ans);
	}
}
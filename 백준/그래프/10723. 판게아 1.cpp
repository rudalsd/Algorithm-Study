#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

struct node {
	int u, v, c;
};

bool cmp(node left, node right)
{
	return left.c < right.c;
}

int vect[100000];
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
		int n, m;
		scanf("%d %d", &n, &m);

		arr.clear();

		for (int i = 1; i < n; i++) {
			int u, c;
			scanf("%d %d", &u, &c);
			arr.push_back({ i,u,c });
		}

		int Max = 987654321;
		ll temp = 0;
		ll ans = 0;

		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);

			arr.push_back({ u,v,c });

			if (Max > c) {
				temp = 0;
				Max = 0;

				for (int j = 0; j < n; j++) {
					vect[j] = j;
				}

				sort(arr.begin(), arr.end(), cmp);

				for (auto& next : arr) {
					const int u = next.u;
					const int v = next.v;
					const int c = next.c;

					if (Find(u) != Find(v)) {
						Union(u, v);
						temp += c;
						Max = max(Max, c);
					}
				}
			}
			
			if (i == 0) {
				ans = temp;
			}
			else {
				ans ^= temp;
			}
		}

		printf("%lld\n", ans);
	}
}
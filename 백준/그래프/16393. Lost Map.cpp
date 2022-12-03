#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define ti tuple<int,int,int>

using namespace std;

int N;
int vect[2501];
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
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	vector<ti> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int dist;
			scanf("%d", &dist);
			if (i < j) {
				pq.emplace_back(dist, i, j);
			}
		}
	}

	sort(pq.begin(), pq.end());

	for (auto& next : pq) {
		int a = get<1>(next);
		int b = get<2>(next);
		if (Find(a) != Find(b)) {
			Union(a, b);
			ans.emplace_back(a, b);
		}
	}

	for (auto next : ans) {
		printf("%d %d\n", next.first, next.second);
	}
}
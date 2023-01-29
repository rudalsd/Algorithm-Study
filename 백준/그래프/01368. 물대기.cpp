#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int i;
	int j;
	int cost;
};

struct cmp {
	bool operator()(node left, node right) {
		return left.cost < right.cost;
	}
};

int N;
vector<node> arr;
int vect[301];

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
		int W;
		scanf("%d", &W);

		arr.push_back({ i,0,W });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int P;
			scanf("%d", &P);

			if (j > i) {
				arr.push_back({ i,j,P });
			}
		}
	}

	sort(arr.begin(), arr.end(), cmp());

	int ans = 0;

	for (auto& next : arr) {
		const int i = next.i;
		const int j = next.j;
		const int cost = next.cost;

		if (Find(i) != Find(j)) {
			ans += cost;
			Union(i, j);
		}
	}

	printf("%d", ans);
}
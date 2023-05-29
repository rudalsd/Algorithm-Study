#include<iostream>
#include<vector>

using namespace std;

int V, E;
int vect[3001];
vector<int> list[3001];

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
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		list[a].push_back(b);
		list[b].push_back(a);

		if (Find(a) != Find(b)) {
			Union(a, b);
		}
	}

	int cnt = 0;
	int temp = Find(1);

	if (list[1].size() % 2 == 1) cnt++;

	for (int i = 2; i <= V; i++) {
		if (list[i].size() % 2 == 1) cnt++;

		if (cnt > 2 || temp != Find(i)) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}
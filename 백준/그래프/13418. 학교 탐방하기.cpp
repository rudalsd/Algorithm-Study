#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long

using namespace std;

struct node {
	int A;
	int B;
	int cost;
};

struct Greater {
	bool operator()(node right, node left) {
		return left.cost < right.cost;
	}
};

struct Less {
	bool operator()(node right, node left) {
		return left.cost > right.cost;
	}
};

int N, M;
int vect[1001];
node arr[500000];

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

ll fatigue(ll a)
{
	ll ret = a;

	for (int i = 1; i <= M; i++) {
		const int A = arr[i].A;
		const int B = arr[i].B;
		const int cost = arr[i].cost;

		if (Find(A) != Find(B)) {
			Union(A, B);
			ret += cost;
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= M; i++) {
		scanf("%d %d", &arr[i].A, &arr[i].B);
		int cost;
		scanf("%d", &cost);
		if (cost == 0) {
			arr[i].cost = 1;
		}
		else {
			arr[i].cost = 0;
		}
	}

	ll max, min;

	for (int i = 0; i <= N; i++) {
		vect[i] = i;
	}

	vect[1] = 0;

	sort(arr + 1, arr + M + 1, Greater());

	max = fatigue(arr[0].cost);

	for (int i = 0; i <= N; i++) {
		vect[i] = i;
	}

	vect[1] = 0;

	sort(arr + 1, arr + M + 1, Less());

	min = fatigue(arr[0].cost);

	printf("%lld", max * max - min * min);
}
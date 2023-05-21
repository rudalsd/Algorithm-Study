#include<iostream>

using namespace std;

int N;
int segTree[4200000];

void updateTree(int node, int s, int e, int idx)
{
	if (idx < s || e < idx) return;
	segTree[node]++;

	if (s != e) {
		int m = (s + e) / 2;
		updateTree(node * 2, s, m, idx);
		updateTree(node * 2 + 1, m + 1, e, idx);
	}
}

void getTree(int node, int s, int e, int idx)
{
	if (s == e) {
		printf("%d\n", s);
		segTree[node]--;
		return;
	}

	int m = (s + e) / 2;

	if (segTree[node * 2] >= idx) {
		getTree(node * 2, s, m, idx);
		segTree[node]--;
	}
	else {
		getTree(node * 2 + 1, m + 1, e, idx - segTree[node * 2]);
		segTree[node]--;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int cmd, X;
		scanf("%d %d", &cmd, &X);

		if (cmd == 1) {
			updateTree(1, 1, 2000000, X);
		}
		else {
			getTree(1, 1, 2000000, X);
		}
	}
}
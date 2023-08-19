#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int A, B, C;
};

bool cmp(node left, node right)
{
	return left.C > right.C;
}

int N, M;
node arr[100000];
int vect[10001];

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int A, int B)
{
	int pA = Find(A);
	int pB = Find(B);

	vect[pB] = pA;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		arr[i] = { A,B,C };
	}

	int s, e;
	cin >> s >> e;

	sort(arr, arr + M, cmp);

	for (int i = 0; i < M; i++) {
		const int A = arr[i].A;
		const int B = arr[i].B;
		const int C = arr[i].C;

		if (Find(A) != Find(B)) {
			Union(A, B);
		}

		if (Find(s) == Find(e)) {
			cout << C;
			return 0;
		}
	}
}
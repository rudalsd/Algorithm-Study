#include<iostream>
#include<stack>
#define ll long long

using namespace std;

int N, M, Q;
int visited[100001];
int vect[100001];
ll cnt[100001];
pair<int, int> arr[100001];
stack<int> edge;

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
	cnt[pa] += cnt[pb];
}

int main()
{
	scanf("%d %d %d", &N, &M, &Q);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	for (int i = 0; i < Q; i++) {
		int A;
		scanf("%d", &A);
		edge.push(A - 1);
		visited[A - 1] = 1;
	}

	for (int i = 0; i < M; i++) {
		if (visited[i] != 1) {
			if (Find(arr[i].first) != Find(arr[i].second)) {
				Union(arr[i].first, arr[i].second);
			}
		}
	}

	ll ans = 0;

	while(!edge.empty()){
		int a = arr[edge.top()].first;
		int b = arr[edge.top()].second;
		edge.pop();

		if (Find(a) != Find(b)) {
			ans += (cnt[Find(a)] * cnt[Find(b)]);
			Union(a, b);
		}
	}

	printf("%lld\n", ans);
}

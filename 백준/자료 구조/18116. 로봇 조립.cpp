#include<iostream>

using namespace std;

int N;
int vect[1000001];
int cnt[1000001];

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < 1000001; i++) {
		vect[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		char cmd;
		cin >> cmd;

		if (cmd == 'I') {
			int a, b;
			cin >> a >> b;
			if (Find(a) != Find(b)) {
				Union(a, b);
			}
		}
		else {
			int a;
			cin >> a;

			cout << cnt[Find(a)] << '\n';
		}
	}
}
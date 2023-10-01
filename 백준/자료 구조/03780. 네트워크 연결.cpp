#include<iostream>

using namespace std;

int T, N;
int vect[20001];
int dist[20001];

pair<int,int> Find(int num)
{
	if (vect[num] == num) return make_pair(num, dist[num]);
	pair<int,int> temp = Find(vect[num]);
	vect[num] = temp.first;
	dist[num] += temp.second;
	return make_pair(vect[num], dist[num]);
}

void Union(int I, int J)
{
	vect[I] = J;
	dist[I] = abs(J - I) % 1000;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			vect[i] = i;
			dist[i] = 0;
		}

		while (1) {
			char cmd;
			cin >> cmd;

			if (cmd == 'E') {
				int I;
				cin >> I;
				Find(I);

				cout << dist[I] << '\n';
			}
			else if (cmd == 'I') {
				int I, J;
				cin >> I >> J;

				Union(I, J);
			}
			else break;
		}
	}
}
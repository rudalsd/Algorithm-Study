#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int u, v;
	double d;
};

bool cmp(node left, node right)
{
	return left.d < right.d;
}

int T, S, P;
vector<node> arr;
pair<int, int> pos[501];
int vect[501];
int cnt;

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cout << fixed;
	cout.precision(2);

	for (int t = 0; t < T; t++) {
		cin >> S >> P;

		arr.clear();
		cnt = 0;

		for (int i = 1; i <= P; i++) {
			int x, y;
			cin >> x >> y;
			pos[i] = { x,y };
			vect[i] = i;
		}

		for (int i = 1; i <= P - 1; i++) {
			for (int j = i + 1; j <= P; j++) {
				int x = pos[i].first - pos[j].first;
				int y = pos[i].second - pos[j].second;
				double d = sqrt(x * x + y * y);
				arr.push_back({ i,j,d });
			}
		}

		sort(arr.begin(), arr.end(), cmp);

		for (auto& next : arr) {
			const int u = next.u;
			const int v = next.v;
			const double d = next.d;

			if (Find(u) != Find(v)) {
				Union(u, v);
				cnt++;
			}

			if (cnt == P - S) {
				cout << d << '\n';
				break;
			}
		}
	}
}
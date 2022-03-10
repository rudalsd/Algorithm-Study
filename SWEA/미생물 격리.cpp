#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cell {
	int y;
	int x;
	long mount;
	int dir;
};

bool cmp(cell left, cell right) {
	return left.mount > right.mount;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<cell> vect;
		for (int i = 0; i < K; i++) {
			int y, x, mount, dir;
			cin >> y >> x >> mount >> dir;
			vect.push_back({ y,x,mount,dir });
		}

		for (int m = 0; m < M; m++)
		{
			sort(vect.begin(), vect.end(), cmp);

			for (int i = 0; i < vect.size(); i++) {
				if (vect[i].dir == 1) {
					vect[i].y -= 1;
				}
				else if (vect[i].dir == 2) {
					vect[i].y += 1;
				}
				else if (vect[i].dir == 3) {
					vect[i].x -= 1;
				}
				else {
					vect[i].x += 1;
				}
			}

			for (int i = vect.size() - 1; i >= 0; i--) {
				if (vect[i].y == 0 || vect[i].y == N - 1 || vect[i].x == 0 || vect[i].x == N - 1) {
					if (vect[i].dir == 1) {
						vect[i].dir = 2;
					}
					else if (vect[i].dir == 2) {
						vect[i].dir = 1;
					}
					else if (vect[i].dir == 3) {
						vect[i].dir = 4;
					}
					else {
						vect[i].dir = 3;
					}
					vect[i].mount /= 2;
					if (vect[i].mount == 0)
					{
						vect.erase(vect.begin() + i);
					}
				}
			}

			for (int i = 0; i < vect.size() - 1; i++) {
				for (int j = vect.size() - 1; j >= i + 1; j--) {
					if (vect[i].y == vect[j].y && vect[i].x == vect[j].x) {
						vect[i].mount += vect[j].mount;
						vect.erase(vect.begin() + j);
					}
				}
			}

		}

		int sum = 0;

		for (int i = 0; i < vect.size(); i++) {
			sum += vect[i].mount;
		}

		cout << "#" << t << " " << sum << endl;
	}
}
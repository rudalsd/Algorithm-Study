#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
	float x;
	float y;
	int dir;
	int energy;
};

bool cmp(Node left, Node right)
{
	if (left.dir < right.dir) return 1;
	if (left.dir > right.dir) return 0;
	if (left.y < right.y) return 1;
	if (left.y > right.y) return 0;
	return left.x < right.x;

}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		float x, y;
		int dir, energy;
		vector<Node> v;
		int bucket[1001] = { 0 };

		Node init;

		for (int i = 0; i < N; i++) {
			scanf("%f%f%d%d", &x, &y, &dir, &energy);
			init = { x,y,dir,energy };
			v.push_back(init);
		}

		sort(v.begin(), v.end(), cmp);

		int sum = 0;

		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i].dir == 0)
				{
					if (v[i].x == v[j].x && v[j].dir == 1 && v[i].y < v[j].y) {
						bucket[i]++;
						bucket[j]++;
					}
					if (v[j].dir == 2 && v[j].y - v[i].y == v[j].x - v[i].x) {
						if (v[j].y - v[i].y > 0) {
							bucket[i]++;
							bucket[j]++;
						}
					}
					if (v[j].dir == 3 && -(v[j].y - v[i].y) == v[j].x - v[i].x) {
						if (v[j].y - v[i].y > 0) {
							bucket[i]++;
							bucket[j]++;
						}
					}
				}
				else if (v[i].dir == 2)
				{
					if (v[i].y == v[j].y && v[j].dir == 3 && v[j].x < v[i].x) {
						bucket[i]++;
						bucket[j]++;
					}
				}
				else if (v[i].dir == 1)
				{
					if (v[j].dir == 2 && -(v[j].y - v[i].y) == v[j].x - v[i].x) {
						if (v[i].y - v[j].y > 0) {
							bucket[i]++;
							bucket[j]++;
						}
					}
					if (v[j].dir == 3 && v[j].y - v[i].y == v[j].x - v[i].x) {
						if (v[i].y - v[j].y > 0) {
							bucket[i]++;
							bucket[j]++;
						}
					}
				}
			}
		}

		for (int i = v.size() - 1; i >= 0; i--) {
			if (bucket[i] == 0)
				v.erase(v.begin() + i);
		}

		if (v.size() != 0) {
			while (1)
			{
				for (int i = 0; i < v.size(); i++) {
					if (v[i].dir == 0) {
						v[i].y += 0.5;
					}
					else if (v[i].dir == 1) {
						v[i].y -= 0.5;
					}
					else if (v[i].dir == 2) {
						v[i].x -= 0.5;
					}
					else {
						v[i].x += 0.5;
					}
				}

				for (int i = 0; i < v.size() - 1; i++) {
					int flag = 0;
					for (int j = v.size() - 1; j >= i + 1; j--) {
						if (v[i].x == v[j].x && v[i].y == v[j].y) {
							flag = 1;
							sum += v[j].energy;
							v.erase(v.begin() + j);
						}
					}
					if (flag == 1) {
						sum += v[i].energy;
						v.erase(v.begin() + i);
						i -= 1;
					}
					if (v.size() <= 1)break;
				}

				for (int i = v.size() - 1; i >= 0; i--) {
					if (v[i].y > 1000 || v[i].y < -1000 || v[i].x >1000 || v[i].x < -1000)
						v.erase(v.begin() + i);
				}

				if (v.size() <= 1) break;

			}
		}

		cout << "#" << t << " " << sum << endl; 
	}
}
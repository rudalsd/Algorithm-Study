#include <iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

struct pos {
	int x;
	int y;
};

pos arr[6000];
int vect[3001];
unordered_map<int, int> m;

int N;

int Find(int n)
{
	if (vect[n] == n) return n;
	return vect[n] = Find(vect[n]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa != pb) {
		vect[pb] = pa;
	}
}

bool cmp(pos left, pos right)
{
	if (left.x == right.x) return left.y <= right.y;
	return left.x <= right.x;
}

int closs(pos p1, pos p2, pos p3) {         //외적을 통해 방향을 리턴
	int cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

	if (cross_product > 0) {
		return 1;
	}
	else if (cross_product < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N * 2; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	for (int i = 0; i < N; i++) {
		sort(arr + i * 2, arr + (i + 1) * 2, cmp);
	}

	for (int i = 0; i < N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int l1 = closs(arr[i * 2], arr[i * 2 + 1], arr[j * 2]) * closs(arr[i * 2], arr[i * 2 + 1], arr[j * 2 + 1]);
			int l2 = closs(arr[j * 2], arr[j * 2 + 1], arr[i * 2]) * closs(arr[j * 2], arr[j * 2 + 1], arr[i * 2 + 1]);
			if (l1 == 0 && l2 == 0) {            //두 선이 일직선상에 있을 때
				if (cmp(arr[j * 2], arr[i * 2 + 1]) && cmp(arr[i * 2], arr[j * 2 + 1])) {
					if (Find(i) != Find(j)) {
						Union(i, j);
					}
				}
			}
			else if (l1 <= 0 && l2 <= 0) {
				if (Find(i) != Find(j)) {
					Union(i, j);
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		m[Find(i)]++;		//집합에 속해있다면 선분을 map에 추가
	}

	int ans = 0;

	for (auto it = m.begin(); it != m.end(); it++) {
		if (ans < it->second) {	//집합 중 가장 큰 집합을 ans에 대입
			ans = it->second;
		}
	}

	cout << m.size() << endl << ans;
}
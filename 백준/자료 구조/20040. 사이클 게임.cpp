#include <iostream>

using namespace std;

int n, m;

int vect[500000];

int Find(int num) {												//부모를 찾는 함수
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b) {										//하나로 합치는 함수
	int pa = Find(a);
	int pb = Find(b);
	vect[pb] = pa;
}

int main()
{
	cin >> n >> m;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (Find(a) != Find(b)) {								//부모가 다르다면 합치고 cnt++
			Union(a, b);
			cnt++;
		}
		else {													//부모가 같다면 cnt출력 후 종료
			cout << cnt;
			return 0;
		}
	}

	cout << 0;													//사이클이 완성되지 않았다면 0 출력
}
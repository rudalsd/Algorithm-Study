#include <iostream>

using namespace std;

int n, m;

int vect[500000];

int Find(int num) {												//�θ� ã�� �Լ�
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b) {										//�ϳ��� ��ġ�� �Լ�
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
		if (Find(a) != Find(b)) {								//�θ� �ٸ��ٸ� ��ġ�� cnt++
			Union(a, b);
			cnt++;
		}
		else {													//�θ� ���ٸ� cnt��� �� ����
			cout << cnt;
			return 0;
		}
	}

	cout << 0;													//����Ŭ�� �ϼ����� �ʾҴٸ� 0 ���
}
#include<iostream>
#include<vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct fall {																//������ ���� id�� �ð��� ����
	int a;
	int time;
};

bool cmp(fall left, fall right) {											//�������� ���� �񱳸� ���� cmp
	if (left.time == right.time) return left.a < right.a;
	return left.time < right.time;
}

int N, L, k;

int arr[100000];

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> L >> k;
		vector<fall> vect;
		vector<int> l;
		vector<int> r;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < N; i++) {
			int p, a;
			scanf("%d %d", &p, &a);
			if (a < 0) {													//�浹���� �ʴ´ٰ� �������� �� �������� �������� �ð� ����
				l.push_back(p + 1);
			}
			else {															//�浹���� �ʴ´ٰ� �������� �� ���������� �������� �ð� ����
				r.push_back(L - p + 1);
			}
			arr[i] = a;
		}

		sort(r.begin(), r.end());											//������������ ����

		for (int i = 0; i < l.size(); i++) {								//���ʿ� �ִ� id�鿡 ���������� �������� �������� �ð� ����
			vect.push_back({ arr[i], l[i] });
		}

		for (int i = 0; i < r.size(); i++) {								//�����ʿ� �ִ� id�鿡 ���������� ���������� �������� �ð� ����
			vect.push_back({ arr[N - i - 1], r[i] });
		}

		sort(vect.begin(), vect.end(), cmp);								//����

		cout << vect[k - 1].a << endl;
	}
}
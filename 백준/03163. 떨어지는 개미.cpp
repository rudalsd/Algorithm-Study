#include<iostream>
#include<vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct fall {																//떨어질 때의 id와 시간을 저장
	int a;
	int time;
};

bool cmp(fall left, fall right) {											//떨어지는 순서 비교를 위한 cmp
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
			if (a < 0) {													//충돌하지 않는다고 가정했을 때 왼쪽으로 떨어지는 시간 저장
				l.push_back(p + 1);
			}
			else {															//충돌하지 않는다고 가정했을 때 오른쪽으로 떨어지는 시간 저장
				r.push_back(L - p + 1);
			}
			arr[i] = a;
		}

		sort(r.begin(), r.end());											//오름차순으로 정렬

		for (int i = 0; i < l.size(); i++) {								//왼쪽에 있는 id들에 순차적으로 왼쪽으로 떨어지는 시간 대입
			vect.push_back({ arr[i], l[i] });
		}

		for (int i = 0; i < r.size(); i++) {								//오른쪽에 있는 id들에 순차적으로 오른쪽으로 떨어지는 시간 대입
			vect.push_back({ arr[N - i - 1], r[i] });
		}

		sort(vect.begin(), vect.end(), cmp);								//정렬

		cout << vect[k - 1].a << endl;
	}
}
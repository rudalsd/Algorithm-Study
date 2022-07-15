#include<iostream>
#include<algorithm>
#include<stack>

#define ll long long

using namespace std;

struct pos
{
	ll x;
	ll y;
};

pos arr[100001];

int N;

ll ccw(pos a, pos b, pos c)		//점이 직선의 반시계방향에 있으면 양수, 시계방향에 있으면 음수, 일직선상이면 0 return
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmp(pos left, pos right)	//가장 왼쪽 아래에 있는 점 찾기
{
	if (left.y != right.y) return left.y < right.y;
	return left.x < right.x;
}

bool cmp2(pos left, pos right)	//가장 왼쪽 아래에 있는 점 기준 반시계방향으로 정렬
{
	ll p = ccw(arr[0], left, right);
	if (p > 0) {
		return true;
	}
	else if (p < 0) {
		return false;
	}
	else {
		if (left.y != right.y) return left.y < right.y;
		return left.x < right.x;
	}
}

int main()
{
	cin >> N;
	stack <int> s;
	s.push(0);
	s.push(1);

	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + N, cmp);

	sort(arr + 1, arr + N, cmp2);

	int next = 2;

	while (next < N)
	{
		while (s.size() >= 2) {		//stack에 점이 2개 이상 있다면
			int second = s.top();
			s.pop();
			int first = s.top();

			if (ccw(arr[first], arr[second], arr[next]) > 0) {	//다음 점이 직선의 반시계 방향에 있다면
				s.push(second);
				break;
			}
		}

		s.push(next);
		next++;
	}

	printf("%d", s.size());
}
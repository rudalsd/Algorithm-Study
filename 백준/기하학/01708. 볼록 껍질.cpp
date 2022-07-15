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

ll ccw(pos a, pos b, pos c)		//���� ������ �ݽð���⿡ ������ ���, �ð���⿡ ������ ����, ���������̸� 0 return
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool cmp(pos left, pos right)	//���� ���� �Ʒ��� �ִ� �� ã��
{
	if (left.y != right.y) return left.y < right.y;
	return left.x < right.x;
}

bool cmp2(pos left, pos right)	//���� ���� �Ʒ��� �ִ� �� ���� �ݽð�������� ����
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
		while (s.size() >= 2) {		//stack�� ���� 2�� �̻� �ִٸ�
			int second = s.top();
			s.pop();
			int first = s.top();

			if (ccw(arr[first], arr[second], arr[next]) > 0) {	//���� ���� ������ �ݽð� ���⿡ �ִٸ�
				s.push(second);
				break;
			}
		}

		s.push(next);
		next++;
	}

	printf("%d", s.size());
}
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct line {
	int h;
	int o;
};

struct cmp {		//priority_queue�� ������ ���� ��ǥ�� �������� ���� �������� ����
	bool operator()(line right, line left)
	{
		if (left.h == right.h) return left.o < right.o;
		return left.h < right.h;
	}
};

bool comp(line left, line right)	//���е��� �� ��ǥ�� �������� �������� ����
{
	if (left.o == right.o) return left.h < right.h;
	return left.o < right.o;
};

int n, d;
vector<line> arr;
priority_queue<line, vector<line>, cmp> pqAns;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int h, o;
		scanf("%d %d", &h, &o);
		if (h < o) {		//��ǩ���� �� ���� ���� ���� �ֱ�
			arr.push_back({ h,o });
		}
		else {
			arr.push_back({ o,h });
		}
	}

	sort(arr.begin(), arr.end(), comp);

	cin >> d;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int h = arr[i].h;
		int o = arr[i].o;

		if (o - h <= d) {	//������ ���̰� d�� ���� ������ push
			pqAns.push({ h,o });
		}

		while (!pqAns.empty())
		{
			int h = pqAns.top().h;
			if (h < o - d) {	//���� ���� �տ� �ִ� ������ ����L�� ����� pop
				pqAns.pop();
			}
			else {
				break;
			}
		}

		if (ans < pqAns.size()) {	//pq�� ����� ������ ����
			ans = pqAns.size();
		}
	}

	cout << ans;
}
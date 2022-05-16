#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

struct Node {												//������ ��ǥ�� �����ϱ� ���� Node struct
	double x;
	double y;
};

struct Edge {												//������ ���� ����� �����ϱ� ���� Edge struct
	int start;
	int end;
	double cost;
};

bool cmp(Edge left, Edge right) {							//sort�� ���� cmp �Լ�
	return left.cost < right.cost;
}

Node arr[110];												//������ ��ǥ�� ������ �迭
vector<Edge> vect;											//edge�� ������ �迭

int parent[110];											//�� ����� �θ� ������ �迭

int Find(int num) {											//�θ� ã�� �Լ� Find
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {									//��ġ�� ���� Union �Լ�
	int pa = Find(a);
	int pb = Find(b);
	parent[pb] = pa;
}

int main()
{
	cin >> n;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;						//��ǥ �Է�
		parent[i] = i;
	}

	for (int i = 1; i <= n - 1; i++) {						//��� �迭�� ���鼭 edge�� ����
		for (int j = i + 1; j <= n; j++) {
			double cost;
			double y = arr[i].y - arr[j].y;
			double x = arr[i].x - arr[j].x;
			cost = sqrt(y * y + x * x);
			vect.push_back({ i,j,cost });
		}
	}

	sort(vect.begin(), vect.end(), cmp);					//�Ÿ����� ���� �������� ����

	for (int i = 0; i < vect.size(); i++) {
		if (Find(vect[i].start) != Find(vect[i].end)) {		//union find
			Union(vect[i].start, vect[i].end);
			ans += vect[i].cost;							//������ ������ ans += cost
		}
	}

	printf("%.2lf", ans);
}
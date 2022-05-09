#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

struct Node {
	int a;
	int b;
	int cost;
};

bool cmp(Node left, Node right) {
	return left.cost < right.cost;
}

int vect[100005];
vector<Node> list;
vector<int> cost;

int parent(int a) {											//�θ� ã��
	if (vect[a] == a) {
		return a;
	}
	return vect[a] = parent(vect[a]);
}

void Union(int a, int b) {									//��ġ��
	int pa = parent(a);
	int pb = parent(b);
	vect[pb] = pa;											//pb�� �θ� pa�� �ٲ��ֱ�
}

int main()
{
	int N, M;
	int result = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list.push_back({ a,b,c });
	}

	sort(list.begin(), list.end(), cmp);

	for (int i = 0; i < list.size(); i++) {
		if (parent(list[i].a) != parent(list[i].b)) {		//�θ� �ٸ��ٸ�
			Union(list[i].a, list[i].b);					//Union
			cost.push_back(list[i].cost);
			result += list[i].cost;
		}
	}

	cout << result - cost[cost.size()-1] << endl;
}
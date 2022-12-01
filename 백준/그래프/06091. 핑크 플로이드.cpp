#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N;
int vect[1050];	//�θ�
vector<int> list[1050];	//���� ����Ʈ

struct node {
	int from;
	int to;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int Find(int num)		//�θ� ã��
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)	//��ġ��
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	scanf("%d", &N);

	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int dist;
			scanf("%d", &dist);
			pq.push({ i,j,dist });	//�Ÿ������� push
		}
	}

	while (!pq.empty()) {
		const int from = pq.top().from;
		const int to = pq.top().to;
		const int dist = pq.top().dist;
		pq.pop();

		if (Find(from) != Find(to)) {	//�θ� �ٸ��ٸ�
			Union(from, to);			//��ġ��
			list[from].push_back(to);	//���� ����Ʈ �߰�
			list[to].push_back(from);
		}
	}

	for (int i = 1; i <= N; i++) {
		sort(list[i].begin(), list[i].end());	//����
		printf("%d ", list[i].size());
		for (auto next : list[i]) {
			printf("%d ", next);
		}
		printf("\n");
	}
}
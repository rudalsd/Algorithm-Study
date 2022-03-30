#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int vect[100011];

struct Node {
	int node;
	long long pos;
};

struct Edge {
	int from;
	int to;
	long long dist;
};

//struct Edge {
//	int to;
//	long dist;
//};

bool cmp(Node left, Node right) {
	return left.pos < right.pos;
}

bool cmpE(Edge left, Edge right) {
	return left.dist < right.dist;
}

//struct compare {
//	bool operator()(Edge right, Edge left) {
//		return left.dist < right.dist;
//	}
//};

int Parent(int num)
{
	if (vect[num] == num) return num;
	int ret = Parent(vect[num]);
	vect[num] = ret;
	return ret;
}

void Union(int a, int b)
{
	vect[Parent(b)] = Parent(a);
}

vector<Node> X;
vector<Node> Y;
vector<Node> Z;
//vector<Edge> list[100001];
vector<Edge> planet;
long long dist;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		vect[i] = i;

		X.push_back({ i,x });
		Y.push_back({ i,y });
		Z.push_back({ i,z });
	}

	sort(X.begin(), X.end(), cmp);
	sort(Y.begin(), Y.end(), cmp);
	sort(Z.begin(), Z.end(), cmp);

	/*for (int i = 0; i < N - 1; i++) {
		list[X[i].node].push_back({ X[i + 1].node,abs(X[i + 1].pos - X[i].pos) });
		list[Y[i].node].push_back({ Y[i + 1].node,abs(Y[i + 1].pos - Y[i].pos) });
		list[Z[i].node].push_back({ Z[i + 1].node,abs(Z[i + 1].pos - Z[i].pos) });
		list[X[i + 1].node].push_back({ X[i].node,abs(X[i + 1].pos - X[i].pos) });
		list[Y[i + 1].node].push_back({ Y[i].node,abs(Y[i + 1].pos - Y[i].pos) });
		list[Z[i + 1].node].push_back({ Z[i].node,abs(Z[i + 1].pos - Z[i].pos) });
	}*/

	/*for (int i = 1; i <= N; i++) {
		sort(list[i].begin(), list[i].end(), cmpE);
	}*/

	/*priority_queue<Edge, vector<Edge>, compare> pq;
	pq.push({ 1,0 });

	while (!pq.empty())
	{
		int curNode = pq.top().to;
		int curCost = pq.top().dist;
		pq.pop();

		if (vect[curNode] == 1)continue;
		vect[curNode] = 1;

		dist += curCost;

		for (int i = 0; i < list[curNode].size(); i++) {
			pq.push({ list[curNode][i].to, list[curNode][i].dist });
		}
	}*/

	for (int i = 0; i < N - 1; i++) {
		planet.push_back({ X[i].node,X[i + 1].node,abs(X[i + 1].pos - X[i].pos) });
		planet.push_back({ Y[i].node,Y[i + 1].node,abs(Y[i + 1].pos - Y[i].pos) });
		planet.push_back({ Z[i].node,Z[i + 1].node,abs(Z[i + 1].pos - Z[i].pos) });
	}

	sort(planet.begin(), planet.end(), cmpE);

	for (int i = 0; i < planet.size(); i++) {
		int from = Parent(planet[i].from);
		int to = Parent(planet[i].to);
		long long cost = planet[i].dist;
		if (Parent(from) != Parent(to)) {
			Union(from, to);
			dist += cost;
		}
	}

	cout << dist;
}
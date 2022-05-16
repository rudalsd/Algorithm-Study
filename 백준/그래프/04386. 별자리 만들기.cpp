#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

struct Node {												//각각의 좌표를 저장하기 위한 Node struct
	double x;
	double y;
};

struct Edge {												//각각의 점과 비용을 저장하기 위한 Edge struct
	int start;
	int end;
	double cost;
};

bool cmp(Edge left, Edge right) {							//sort를 위한 cmp 함수
	return left.cost < right.cost;
}

Node arr[110];												//각각의 좌표를 저장할 배열
vector<Edge> vect;											//edge를 저장할 배열

int parent[110];											//각 노드의 부모를 저장할 배열

int Find(int num) {											//부모를 찾는 함수 Find
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {									//합치기 위한 Union 함수
	int pa = Find(a);
	int pb = Find(b);
	parent[pb] = pa;
}

int main()
{
	cin >> n;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;						//좌표 입력
		parent[i] = i;
	}

	for (int i = 1; i <= n - 1; i++) {						//모든 배열을 돌면서 edge를 저장
		for (int j = i + 1; j <= n; j++) {
			double cost;
			double y = arr[i].y - arr[j].y;
			double x = arr[i].x - arr[j].x;
			cost = sqrt(y * y + x * x);
			vect.push_back({ i,j,cost });
		}
	}

	sort(vect.begin(), vect.end(), cmp);					//거리순에 따라 오름차순 정렬

	for (int i = 0; i < vect.size(); i++) {
		if (Find(vect[i].start) != Find(vect[i].end)) {		//union find
			Union(vect[i].start, vect[i].end);
			ans += vect[i].cost;							//합쳐질 때마다 ans += cost
		}
	}

	printf("%.2lf", ans);
}
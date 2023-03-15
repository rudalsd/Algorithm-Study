#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int u, v, w;
};

bool cmp(node left, node right)
{
	return left.w < right.w;
}

int N;
int ans;
vector<node> arr;
vector<pair<int, int>> list;
int vect[201];

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}
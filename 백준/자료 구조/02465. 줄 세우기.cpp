#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>

using namespace std;

int N;
int segTree[262222];
unordered_map<int, int> m;
set<int> se;
vector<int> arr;
vector<int> ans;
int seq[100000];

void makeTree(int node, int s, int e)
{
	if (s == e) {
		segTree[node] += m[arr[s]];
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

void updateTree(int node, int s, int e, int idx)
{
	segTree[node]--;
	if (s == e) {
		ans.push_back(arr[s]);
		return;
	}

	int m = (s + e) / 2;
	if (segTree[node * 2] >= idx) {
		updateTree(node * 2, s, m, idx);
	}
	else {
		updateTree(node * 2 + 1, m + 1, e, idx - segTree[node * 2]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		se.insert(n);
		m[n]++;
	}
	
	arr.push_back(-1);

	for (auto& next : se) {
		arr.push_back(next);
	}

	makeTree(1, 1, arr.size() - 1);

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		updateTree(1, 1, arr.size() - 1, seq[i] + 1);
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> mergeSortTree[262222];
int arr[100001];
int ans;

void merge(int node, int s, int e) {
	int s_size = mergeSortTree[node * 2].size();
	int e_size = mergeSortTree[node * 2 + 1].size();
	int i = 0;
	int j = 0;
	while (1) {
		if (mergeSortTree[node * 2][i] < mergeSortTree[node * 2 + 1][j]) {
			mergeSortTree[node].push_back(mergeSortTree[node * 2][i++]);
		}
		else {
			mergeSortTree[node].push_back(mergeSortTree[node * 2 + 1][j++]);
		}

		if (i == s_size || j == e_size) {
			break;
		}
	}

	if (i == s_size) {
		for (j; j < e_size; j++) {
			mergeSortTree[node].push_back(mergeSortTree[node * 2 + 1][j]);
		}
	}
	else {
		for (i; i < s_size; i++) {
			mergeSortTree[node].push_back(mergeSortTree[node * 2][i]);
		}
	}
}

void makeTree(int node, int s, int e)
{
	if (s == e) {
		mergeSortTree[node].push_back(arr[s]);
		return;
	}

	int m = (s + e) / 2;
	makeTree(node * 2, s, m);
	makeTree(node * 2 + 1, m + 1, e);

	merge(node, s, e);
}

void getTree(int node, int s, int e, int i, int j, int k)
{
	if (e < i || j < s) return;
	if (i <= s && e <= j) {
		ans += mergeSortTree[node].end() - upper_bound(mergeSortTree[node].begin(), mergeSortTree[node].end(), k);
		return;
	}

	int m = (s + e) / 2;
	getTree(node * 2, s, m, i, j, k);
	getTree(node * 2 + 1, m + 1, e, i, j, k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	makeTree(1, 1, N);

	cin >> M;

	for (int a = 0; a < M; a++) {
		int i, j, k;
		cin >> i >> j >> k;
		ans = 0;

		getTree(1, 1, N, i, j, k);

		cout << ans << '\n';
	}
}
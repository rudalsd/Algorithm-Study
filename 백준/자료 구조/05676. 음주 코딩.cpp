#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int N, K;
int arr[100001];
int segTree[263000];
vector<char>ans;

int invert(int num)
{
	if (num > 0) return 1;
	else if (num < 0) return -1;
	return 0;
}

int makeTree(int node, int start, int end)
{
	if (start == end) return segTree[node] = arr[start];

	int mid = (start + end) / 2;
	int left = makeTree(node * 2, start, mid);
	int right = makeTree(node * 2 + 1, mid + 1, end);

	return segTree[node] = left * right;
}

int changeTree(int node, int start, int end, int idx, int V)
{
	if (idx < start || end < idx) return segTree[node];
	if (start == end) return segTree[node] = V;

	int mid = (start + end) / 2;
	int left = changeTree(node * 2, start, mid, idx, V);
	int right = changeTree(node * 2 + 1, mid + 1, end, idx, V);

	return segTree[node] = left * right;
}

int getTree(int node, int start, int end, int sidx, int eidx)
{
	if (start > eidx || end < sidx) return 1;
	if (sidx <= start && end <= eidx) return segTree[node];

	int mid = (start + end) / 2;
	int left = getTree(node * 2, start, mid, sidx, eidx);
	int right = getTree(node * 2 + 1, mid + 1, end, sidx, eidx);

	return left * right;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> N >> K) {
		memset(segTree, 0, sizeof(segTree));
		ans.clear();

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			arr[i] = invert(arr[i]);
		}

		makeTree(1, 1, N);

		for (int k = 0; k < K; k++) {
			char ch;
			cin >> ch;

			if (ch == 'C') {
				int i, V;
				cin >> i >> V;

				V = invert(V);
				changeTree(1, 1, N, i, V);
				arr[i] = V;
			}
			else {
				int i, j;
				cin >> i >> j;

				int temp = getTree(1, 1, N, i, j);

				if (temp < 0) ans.push_back('-');
				else if (temp > 0) ans.push_back('+');
				else ans.push_back('0');
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << endl;
	}
}
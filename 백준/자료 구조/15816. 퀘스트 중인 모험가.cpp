#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct query {
	int cmd;
	int L, R;
};

int N, M;
vector<int> quest;
query arr[1000000];
int segTree[6000000];
int list[1000000];

void updateTree(int idx)
{
	while (idx != 0) {
		segTree[idx]++;
		idx >>= 1;
	}
}

int getTree(int L, int R)
{
	int ret = 0;

	while (L <= R) {
		if (L & 1) {
			ret += segTree[L];
			L++;
		}
		if (~R & 1) {
			ret += segTree[R];
			R--;
		}

		L >>= 1;
		R >>= 1;
	}

	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int Q;
		scanf("%d", &Q);

		list[i] = Q;
		quest.push_back(Q);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 1) {
			int X;
			scanf("%d", &X);

			quest.push_back(X);
			arr[i] = { cmd,X,0 };
		}
		else {
			int L, R;
			scanf("%d %d", &L, &R);

			quest.push_back(L);
			quest.push_back(R);
			arr[i] = { cmd,L,R };
		}
	}

	sort(quest.begin(), quest.end());
	quest.erase(unique(quest.begin(), quest.end()), quest.end());
	int n = quest.size();

	for (int i = 0; i < N; i++) {
		auto idx = lower_bound(quest.begin(), quest.end(), list[i]) - quest.begin();
		updateTree(n + idx);
	}

	for (int i = 0; i < M; i++) {
		int cmd = arr[i].cmd;
		int L = arr[i].L;
		int R = arr[i].R;

		if (cmd == 1) {
			auto idx = lower_bound(quest.begin(), quest.end(), L) - quest.begin();
			updateTree(n + idx);
		}
		else {
			auto Lidx = lower_bound(quest.begin(), quest.end(), L) - quest.begin();
			auto Ridx = lower_bound(quest.begin(), quest.end(), R) - quest.begin();

			printf("%d\n", R - L + 1 - getTree(n + Lidx, n + Ridx));
		}
	}
}

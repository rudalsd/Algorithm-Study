#include<iostream>
#include<queue>
#include<string>

using namespace std;

int N, k;
int visited[2][100000];

struct node {
	int pos;
	int cnt;
	bool isLeft;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> k;

	string arr[2];
	cin >> arr[0] >> arr[1];

	queue<node> q;

	q.push({ 0,0,true });
	visited[0][0] = 1;

	while (!q.empty()) {
		const int pos = q.front().pos;
		const int cnt = q.front().cnt;
		const bool isLeft = q.front().isLeft;
		q.pop();

		if (pos + k >= N || pos == N - 1) {
			cout << 1;
			return 0;
		}

		if (isLeft == true) {
			if (pos - 1 > cnt && arr[0][pos - 1] == '1' && visited[0][pos - 1] != 1) {
				visited[0][pos - 1] = 1;
				q.push({ pos - 1,cnt + 1,true });
			}
			if (arr[0][pos + 1] == '1' && visited[0][pos + 1] != 1) {
				visited[0][pos + 1] = 1;
				q.push({ pos + 1,cnt + 1,true });
			}
			if (arr[1][pos + k] == '1' && visited[1][pos + k] != 1) {
				visited[1][pos + k] = 1;
				q.push({ pos + k,cnt + 1,false });
			}
		}
		else {
			if (pos - 1 > cnt && arr[1][pos - 1] == '1' && visited[1][pos - 1] != 1) {
				visited[1][pos - 1] = 1;
				q.push({ pos - 1,cnt + 1,false });
			}
			if (arr[1][pos + 1] == '1' && visited[1][pos + 1] != 1) {
				visited[1][pos + 1] = 1;
				q.push({ pos + 1,cnt + 1,false });
			}
			if (arr[0][pos + k] == '1' && visited[0][pos + k] != 1) {
				visited[0][pos + k] = 1;
				q.push({ pos + k,cnt + 1,true });
			}
		}
	}

	cout << 0;
}

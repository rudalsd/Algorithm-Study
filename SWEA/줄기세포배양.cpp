#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int y;
	int x;
	int life;
	int hour;
};

class cmp {
public:
	bool operator()(Node right, Node left) {
		if (left.hour < right.hour) return 1;
		if (left.hour > right.hour) return 0;

		return left.life > right.life;
	}
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[700][700];

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		for (int i = 0; i < 700; i++)
			for (int j = 0; j < 700; j++)
				arr[i][j] = 0;
		int N, M, K;
		priority_queue<Node, vector<Node>, cmp> q;

		cin >> N >> M >> K;

		Node start;

		for (int i = 300; i < 300 + N; i++) {
			for (int j = 300; j < 300 + M; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > 0) {
					start = { i,j,arr[i][j], arr[i][j] + 1 };
					q.push(start);
				}
			}
		}

		while (!q.empty())
		{
			int cy = q.top().y;
			int cx = q.top().x;
			int life = q.top().life;
			int hour = q.top().hour;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = cy + dy[i];
				int xx = cx + dx[i];
				if (arr[yy][xx] == 0 && hour <= K) {
					arr[yy][xx] = hour + life * 2;
					Node next;
					next = { yy,xx,life, hour + life + 1 };
					q.push(next);
				}
			}
		}

		int cnt = 0;

		for (int i = 0; i < 700; i++) {
			for (int j = 0; j < 700; j++) {
				if (arr[i][j] > K)
					cnt++;
			}
		}

		cout << "#" << t << " " << cnt << endl;
	}
}
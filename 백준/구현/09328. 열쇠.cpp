#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

char arr[111][111];			//지도
int visited[111][111];		//방문 여부 체크
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int h, w;
		int key[26] = { 0 };		//몇번 키를 가지고 있는지 체크할 배열
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		queue<pos> q;
		queue<pos> door[26];		//열쇠가 없는 문에 닿았을 때 좌표 저장
		int cnt = 0;
		cin >> h >> w;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}

		string str = "";
		cin >> str;
		if (str != "0") {
			for (int i = 0; i < str.size(); i++) {
				key[str[i] - 'a']++;
			}
		}

		q.push({ 0,0 });
		visited[0][0] = 1;

		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];
				if (yy >= 0 && yy <= h + 1 && xx >= 0 && xx <= w + 1) {
					if (visited[yy][xx] == 1 || arr[yy][xx] == '*') continue;
					visited[yy][xx] = 1;

					if (arr[yy][xx] >= 'A' && arr[yy][xx] <= 'Z') {
						if (key[arr[yy][xx] - 'A'] == 1) {	//열쇠가 있다면 통과
							q.push({ yy,xx });
						}
						else {
							door[arr[yy][xx] - 'A'].push({ yy,xx });	//없다면 좌표를 저장
						}
					}
					else if (arr[yy][xx] >= 'a' && arr[yy][xx] <= 'z') {
						key[arr[yy][xx] - 'a'] = 1;		//키를 가지고 있다고 체크
						while (!door[arr[yy][xx] - 'a'].empty()) {	//키로 열 수 있는 문 좌표 q에 push
							int curKey = arr[yy][xx] - 'a';
							int curY = door[curKey].front().y;
							int curX = door[curKey].front().x;
							door[curKey].pop();
							q.push({ curY,curX });
						}
						q.push({ yy,xx });
					}
					else if (arr[yy][xx] == '$') {		//문서면 cnt++
						cnt++;
						q.push({ yy,xx });
					}
					else {
						q.push({ yy,xx });
					}
				}
			}
		}

		cout << cnt << endl;
	}
}
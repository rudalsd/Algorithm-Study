#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	string str;
	int cnt;
};

int main()
{
	string temp = "";
	unordered_map<string, int> map;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char ch;
			cin >> ch;
			temp += ch;
		}
	}

	queue<pos> q;
	q.push({ temp, 0 });

	int result = -1;

	map[temp] = 1;

	while (!q.empty())
	{
		string str = q.front().str;
		int cnt = q.front().cnt;
		q.pop();
		if (str == "123456780") {										//원하는 배열이 완성되면 결괏값에 cnt를 넣고 반복문 탈출
			result = cnt;
			break;
		}
		int temp[3][3];
		int y, x;
		for (int i = 0; i < 3; i++) {									//방향 배열 사용을 위해 string을 풀어서 temp배열에 넣기
			for (int j = 0; j < 3; j++) {
				temp[i][j] = str[i * 3 + j] - '0';
				if (temp[i][j] == 0) {									//0의 위치를 y와 x에 각각 대입
					y = i;
					x = j;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < 3 && xx >= 0 && xx < 3) {
				swap(temp[y][x], temp[yy][xx]);							//y,x의 값과 yy,xx의 값을 swap
				string s = "";
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						s += to_string(temp[i][j]);
					}
				}
				if (map[s] == 1) {										//이미 만들어진 경우이면
					swap(temp[y][x], temp[yy][xx]);						//원상복구
					continue;
				}
				map[s] = 1;												//처음인 경우 map에 넣기
				q.push({ s,cnt + 1 });
				swap(temp[y][x], temp[yy][xx]);							//원상복구
			}
		}
	}

	cout << result;
}
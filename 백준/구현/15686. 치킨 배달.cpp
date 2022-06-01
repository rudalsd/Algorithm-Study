#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos {			//각 좌표를 저장하기 위한 pos struct
	int y;
	int x;
};

int N, M;
int arr[50][50];		//맵
vector<pos> chicken;	//치킨집의 좌표를 저장할 vector
pos box[13];			//조합을 저장할 배역
int sum;
int ans = 987654321;

void dfs(int level, int num)
{
	if (level == M)
	{
		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					int min = 987654321;
					for (int k = 0; k < M; k++) {
						int y = box[k].y;		//조합으로 뽑은 치킨집의 좌표를 추출
						int x = box[k].x;		//거리를 계산 후 dist에 저장
						int dist = abs(y - i) + abs(x - j);
						if (min > dist) {		//가장 작은 dist를 min에 저장
							min = dist;
						}
					}
					sum += min;			//sum에 min을 더함
				}
			}
		}
		if (ans > sum) {			//가장 작은 sum을 ans에 경신
			ans = sum;
		}
		return;
	}

	for (int i = num; i < chicken.size() - M + 1 + level; i++) {
		box[level] = chicken[i];
		dfs(level + 1, i + 1);
		box[level] = { 0,0 };
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {	//치킨집들을 chicken vector에 push
				chicken.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);

	cout << ans;
}
#include<iostream>
#include<vector>

using namespace std;

struct pos {
	int y;
	int x;
	bool dot;
};

int N;
int arr[101][101];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

vector<pos> gen(vector<pos> vect)	//드래곤 커브 그리기
{
	int idx, y, x;
	int size = vect.size();
	for (int i = 0; i < size; i++) {	//드래곤 커브의 끝 점
		if (vect[i].dot == 1) {
			y = vect[i].y;
			x = vect[i].x;
			vect[i].dot = 0;
			idx = i;
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		if (idx != i) {
			int yy = vect[i].y - y;	//끝 점 기준으로 상대 위치 저장
			int xx = vect[i].x - x;
			int tempX = -yy;
			int tempY = xx;
			xx = x + tempX;		//이동한 점의 좌표
			yy = y + tempY;
			if (i == 0) {	//첫 점은 다음 드래곤 커브의 끝 점
				vect.push_back({ yy,xx,1 });
			}
			else {
				vect.push_back({ yy,xx });
			}
			arr[yy][xx] = 1;
		}
	}

	return vect;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		int yy = y + dy[d];
		int xx = x + dx[d];
		vector<pos> vect;
		vect.push_back({ y,x });
		vect.push_back({ yy,xx,1 });
		arr[y][x] = 1;
		arr[yy][xx] = 1;

		for (int j = 0; j < g; j++) {
			vect = gen(vect);
		}
	}

	int ans = 0;

	for (int i = 0; i < 100; i++) {	//꼭짓점이 모두 드래곤 커브인 정사각형 개수 구하기
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1) {
				ans++;
			}
		}
	}

	printf("%d", ans);
}
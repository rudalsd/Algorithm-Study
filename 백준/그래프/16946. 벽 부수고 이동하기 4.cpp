#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
char arr[1001][1001];							//���� �Է� ���� �迭
int ans[1001][1001];							//������ ����� �迭
int visited[1001][1001];						//�湮�� üũ�� �迭
int dy[4] = { -1,1,0,0 };						//���� �迭
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

void bfs(int y, int x)
{
	queue<pos> q;
	vector<pos> vect;

	q.push({ y,x });
	arr[y][x] = 'a';

	int cnt = 1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '0') {
					arr[yy][xx] = 'a';								//�迭���� 'a'�� �ʱ�ȭ�ϸ鼭 �ٽ� �湮���� ���ϰ� �Ѵ�.
					cnt++;											//�� �� �ִ� ���� ���� ����
					q.push({ yy,xx });
				}
				if (arr[yy][xx] == '1' && visited[yy][xx] != 1) {	//���� ������ visited�� ����ϰ� ��ǥ�� ����
					visited[yy][xx] = 1;
					vect.push_back({ yy,xx });
				}
			}
		}
	}

	for (int i = 0; i < vect.size(); i++) {
		int yy = vect[i].y;
		int xx = vect[i].x;
		visited[yy][xx] = 0;						//�湮 ����� ���ְ�
		ans[yy][xx] += cnt;							//�ش� ��ǥ�� cnt���� ������
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') {
				bfs(i, j);							//�ش� �迭�� ���� '0'�̶��
			}										//bfs�� ������
			else if (arr[i][j] == '1') {
				ans[i][j]++;						//�ش� ���� '1'�̶�� �� ī��Ʈ ������ 1�� �����ش�
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] % 10;					//10���� ���� ������ ���� ����Ѵ�.
		}
		cout << endl;
	}
}
#include <iostream>
#include <queue>

using namespace std;

int N, M, P;
int S[15];																//�̵� ������ �Ÿ� ������ �迭
char arr[1100][1100];
int result[15];															//������ ������ �迭
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Node {
	int P;						//�÷��̾� ��ȣ
	int y;						//y ��ǥ
	int x;						//x ��ǥ
	int cnt;					//�̵� �Ÿ�
	int time;					//���� ��
};

struct cmp {																//time�� �������� ������ ���ٸ� P��ȣ�� �������� ������ ���ٸ� cnt�� �������� ������ ����
	bool operator()(Node right, Node left) {
		if (left.time < right.time) return true;
		if (left.time > right.time) return false;
		if (left.P < right.P) return true;
		if (left.P > right.P) return false;
		return left.cnt < right.cnt;

	}
};

priority_queue<Node, vector<Node>, cmp> pq;

int main()
{
	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] >= '1' && arr[i][j] <= '9') {				//�迭�� ���鼭 ���ڰ� �ִٸ� result[P]��++
				pq.push({ arr[i][j] - '0',i,j,0,0 });
				result[arr[i][j] - '0']++;
			}
		}
	}

	while (!pq.empty())
	{
		int P = pq.top().P;
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().cnt;
		int time = pq.top().time;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '.') {											//���� �� ���� ����ִٸ�
					arr[yy][xx] = P + '0';											//�迭�� P�� �ٲٰ�
					result[P]++;													//�ᱣ���� +1
					if (cnt + 1 == S[P]) {											//�� �Դٸ�
						pq.push({ P,yy,xx,0,time + 1 });							//pq�� cnt�� 0�� �ʱ�ȭ�ϰ�, time�� +1�� ���༭ push
					}
					else {															//���� �� �� �� �ִٸ�
						pq.push({ P,yy,xx,cnt + 1,time });							//cnt++
					}
				}
			}
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << result[i] << " ";
	}
}
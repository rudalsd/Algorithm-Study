#include<iostream>
#include<cstring>
#include<unordered_map>
#include<queue>

using namespace std;

struct node {
	int num;
	int cnt;
};

struct cmp {	//pq정렬
	bool operator()(node right, node left) {
		if (left.cnt == right.cnt) return left.num < right.num;
		return left.cnt < right.cnt;
	}
};

int r, c, k;
int arr[101][101];
int y, x;

void calR()	//R연산
{
	int temp = x;
	x = 0;
	for (int i = 1; i <= y; i++) {
		priority_queue<node, vector<node>, cmp> pq;
		unordered_map<int, int> m;
		for (int j = 1; j <= temp; j++) {
			if (arr[i][j] != 0) {	//0이 아니라면 map에 저장
				m[arr[i][j]]++;
			}
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			pq.push({ it->first, it->second });	//map에 저장된 숫자들을 pq에 push
		}
		memset(arr[i], 0, sizeof(arr[i]));	//해당 행 0으로 초기화

		int size = pq.size();
		size = min(size, 50);
		x = max(x, size * 2);

		for (int j = 1; j <= size * 2; j += 2) {
			int num = pq.top().num;	//행 채우기
			int cnt = pq.top().cnt;
			pq.pop();
			arr[i][j] = num;
			arr[i][j + 1] = cnt;
		}
	}
}

void calC()	//C연산
{
	int temp = y;
	y = 0;
	for (int i = 1; i <= x; i++) {
		priority_queue<node, vector<node>, cmp> pq;
		unordered_map<int, int> m;
		for (int j = 1; j <= temp; j++) {
			if (arr[j][i] != 0) {	//0이 아니라면 map에 저장
				m[arr[j][i]]++;
			}
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			pq.push({ it->first, it->second });	//map에 저장된 숫자들을 pq에 push
		}

		for (int j = 1; j <= temp; j++) {
			arr[j][i] = 0;	//해당 열 0으로 초기화
		}

		int size = pq.size();
		size = min(size, 50);
		y = max(y, size * 2);

		for (int j = 1; j <= size * 2; j += 2) {
			int num = pq.top().num;	//열 채우기
			int cnt = pq.top().cnt;
			pq.pop();
			arr[j][i] = num;
			arr[j + 1][i] = cnt;
		}
	}
}

int main()
{
	scanf("%d %d %d", &r, &c, &k);

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	y = x = 3;

	for (int i = 0; i <= 100; i++) {
		if (arr[r][c] == k) {
			printf("%d", i);
			return 0;
		}

		if (y >= x) {
			calR();
		}
		else {
			calC();
		}
	}

	printf("%d", -1);
}
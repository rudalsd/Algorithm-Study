#include<iostream>

using namespace std;

int n;
int segTree[2111111];

void update(int node, int start, int end, int taste, int N)	//사탕 숫자 update
{
	if (taste > end || taste < start) return;	//범위를 벗어나면

	segTree[node] += N;

	if (start == end) return;	//범위에 완전히 포함되면

	//범위에 일부 포함되면
	int mid = (start + end) / 2;
	update(node * 2, start, mid, taste, N);
	update(node * 2 + 1, mid + 1, end, taste, N);
}

int get(int node, int start, int end, int idx)	//idx번째 사탕의 맛 얻기
{
	if (start == end) {		//범위에 정확히 들어오면
		return start;
	}

	int mid = (start + end) / 2;
	if (segTree[node * 2] >= idx) return get(node * 2, start, mid, idx);	//왼쪽 자식 노드
	return get(node * 2 + 1, mid + 1, end, idx - segTree[node * 2]);		//오른쪽 자식 노드
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int A, B, C;
		scanf("%d", &A);

		if (A == 1) {		//사탕 꺼내기
			scanf("%d", &B);
			int idx = get(1, 1, 1000000, B);
			printf("%d\n", idx);
			update(1, 1, 1000000, idx, -1);
		}
		else {				//사탕 넣고, 빼기
			scanf("%d %d", &B, &C);
			update(1, 1, 1000000, B, C);
		}
	}
}
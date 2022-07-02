#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
long long arr[1000001];			//값들을 저장할 배열
vector<long long> segTree;

int N, M, K;

long long makeTree(int node, int start, int end)	//segmentTree를 만드는 함수
{
	if (start == end) {		//리프 노드
		return segTree[node] = arr[start];
	}
	int mid = (start + end) / 2;

	long long left = makeTree(node * 2, start, mid);	//왼쪽 노드
	long long right = makeTree(node * 2 + 1, mid + 1, end);	//오른쪽 노드

	return segTree[node] = left + right;
}

void changeTree(int node, int start, int end, int idx, long long diff)	//원하는 idx 수 바꾸기
{
	if (start > idx || end < idx) return;	//바꾸고자 하는 idx가 범위 내에 없으면 return
	segTree[node] += diff;			//idx가 범위 내에 있으면 차이만큼 더해줌

	if (start != end) {				//리프 노드가 아닐 때
		int mid = (start + end) / 2;
		changeTree(node * 2, start, mid, idx, diff);	//왼쪽 노드
		changeTree(node * 2 + 1, mid + 1, end, idx, diff);	//오른쪽 노드
	}
}

long long sumTree(int node, int start, int end, int sidx, int eidx)	//sidx ~ eidx까지의 합
{
	if (eidx < start || sidx > end) return 0;	//범위를 벗어나면 0 return
	if (sidx <= start && eidx >= end) return segTree[node];	//범위에 완전 포함되면 해당 노드 값 return

	int mid = (start + end) / 2;
	long long left = sumTree(node * 2, start, mid, sidx, eidx);	//왼쪽 노드
	long long right = sumTree(node * 2 + 1, mid + 1, end, sidx, eidx);	//오른쪽 노드
	return left + right;
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}

	int size = 1 << (int)(ceil(log2(N)) + 1);

	segTree.resize(size);
	makeTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {		//수 바꾸기
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			long long diff = c - arr[b];	//바꾸고자 하는 수와 원래 수의 차
			arr[b] = c;			//원하는 idx의 값 갱신
			changeTree(1, 1, N, b, diff);
		}
		else {		//구간합 구하기
			int b, c;
			scanf("%d %d", &b, &c);
			long long ans = sumTree(1, 1, N, b, c);
			printf("%lld\n", ans);
		}
	}
}
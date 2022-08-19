#include<iostream>
#include<algorithm>

using namespace std;

struct conference {
	int start;
	int end;
};

bool cmp(conference left, conference right) {		//정렬 순서
	if (left.end == right.end) return left.start < right.start;	//시작 시간이 빠를수록
	return left.end < right.end;	//끝나는 시간이 빠를수록
}

int N;
conference arr[100000];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].start, &arr[i].end);
	}

	sort(arr, arr + N, cmp);

	int cur = 0;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (cur <= arr[i].start) {
			cur = arr[i].end;
			ans++;
		}
	}

	printf("%d", ans);
}
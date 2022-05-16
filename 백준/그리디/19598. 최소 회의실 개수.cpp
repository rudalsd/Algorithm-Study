#include<iostream>
#include<queue>

using namespace std;

int N;

struct room {
	int time;
	int cur;
};

struct cmp {													//priority queue cmp구조체 설정
	bool operator()(room right, room left) {
		if (left.time < right.time) return true;				//빠른 시간이 먼저 나오게 설정
		if (left.time > right.time) return false;
		return left.cur < right.cur;							//끝나는 시간이 먼저 나오게 설정
	}
};

int main()
{
	cin >> N;

	priority_queue<room, vector<room>, cmp> pq;

	for (int i = 0; i < N; i++) {
		int  start, end;
		scanf("%d %d", &start, &end);
		pq.push({ start,1 });									//시작하는 시간과 상태에 1 넣기
		pq.push({ end,0 });										//끝나는 시간과 상태에 0 넣기
	}

	int cnt = 0;
	int max = 0;

	while (!pq.empty())
	{
		int time = pq.top().time;
		int cur = pq.top().cur;
		pq.pop();

		if (cur == 1) {											//회의가 시작했으면 cnt++
			cnt++;
		}
		else {													//회의가 끝났으면 cnt--
			cnt--;
		}

		if (max < cnt) {										//필요한 회의실의 최댓값을 max에 넣음
			max = cnt;
		}
	}

	cout << max;
}
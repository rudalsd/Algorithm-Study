#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct line {
	int h;
	int o;
};

struct cmp {		//priority_queue는 선분의 시작 좌표가 작을수록 먼저 나오도록 설정
	bool operator()(line right, line left)
	{
		if (left.h == right.h) return left.o < right.o;
		return left.h < right.h;
	}
};

bool comp(line left, line right)	//선분들을 끝 좌표를 기준으로 오름차순 정렬
{
	if (left.o == right.o) return left.h < right.h;
	return left.o < right.o;
};

int n, d;
vector<line> arr;
priority_queue<line, vector<line>, cmp> pqAns;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int h, o;
		scanf("%d %d", &h, &o);
		if (h < o) {		//좌푯값이 더 작은 값을 먼저 넣기
			arr.push_back({ h,o });
		}
		else {
			arr.push_back({ o,h });
		}
	}

	sort(arr.begin(), arr.end(), comp);

	cin >> d;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int h = arr[i].h;
		int o = arr[i].o;

		if (o - h <= d) {	//선분의 길이가 d를 넘지 않으면 push
			pqAns.push({ h,o });
		}

		while (!pqAns.empty())
		{
			int h = pqAns.top().h;
			if (h < o - d) {	//만약 제일 앞에 있는 선분이 길이L을 벗어나면 pop
				pqAns.pop();
			}
			else {
				break;
			}
		}

		if (ans < pqAns.size()) {	//pq의 사이즈가 선분의 개수
			ans = pqAns.size();
		}
	}

	cout << ans;
}
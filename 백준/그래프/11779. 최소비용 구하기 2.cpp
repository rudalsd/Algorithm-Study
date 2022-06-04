#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Bus {					//노선의 정보를 저장할 struct
	int to;
	int cost;
	vector<int> via;
};

int n, m;
int visited[1001];			//방문 여부 체크
vector<Bus> list[1001];		//버스 도착지와 cost를 저장할 vector list

bool cmp(Bus left, Bus right)	//가격이 낮은 순으로 list를 정렬
{
	return left.cost < right.cost;
}

struct comp {					//가격이 낮은 순으로 priority_queue에서 빠져나옴
	bool operator()(Bus right, Bus left)
	{
		return left.cost < right.cost;
	}
};

int main()
{
	int start, end;
	int ans;				//총 가격 저장할 변수
	vector<int> ansVia;		//경로를 저장할 vector
	cin >> n >> m;

	for (int i = 0; i < m; i++) {	//노선 정보를 list에 입력
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		list[start].push_back({ end,cost });
	}

	cin >> start >> end;

	for (int i = 1; i <= n; i++) {	//가격이 낮은 순으로 정렬
		sort(list[i].begin(), list[i].end(), cmp);
	}

	priority_queue<Bus, vector<Bus>, comp> pq;
	vector<int> via;
	pq.push({ start,0, via });		//시작점을 pq에 넣기


	while (!pq.empty())
	{
		int to = pq.top().to;
		int cost = pq.top().cost;
		vector<int> via = pq.top().via;

		pq.pop();

		if (visited[to] == 1) continue;	//방문했다면 continue
		visited[to]++;
		via.push_back(to);

		if (to == end) {		//목적지에 도착하면 비용과 경로를 저장
			ans = cost;
			ansVia = via;
			break;
		}

		for (int i = 0; i < list[to].size(); i++) {
			int next = list[to][i].to;
			int nextCost = list[to][i].cost;
			if (visited[next] != 1) {		//방문하지 않았다면
				pq.push({ next, cost + nextCost, via });	//다음 노드와 여기까지 오는데 드는 비용, 경로를 pq에 넣기
			}
		}
	}

	printf("%d\n%d\n", ans, ansVia.size());		//출력
	for (int i = 0; i < ansVia.size(); i++) {
		printf("%d ", ansVia[i]);
	}
}
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<fstream>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

int N, M, K;
vector<pair<int, int>> sero[100002];	//Ư�� x��ǥ�� ��ư�� ������ �迭
vector<pair<int, int>> garo[100002];	//Ư�� y��ǥ�� ��ư�� ������ �迭
vector<pair<int, long long>> graph[400015];		//��ư�� ����Ǵ� ���� ����
long long dist[400015];		//�� ��ư���� �������� ������ �ɸ� �ð� ����

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &M, &N, &K);

	bool E = true;

	for (int i = 0; i <= (K + 1) * 2 + 1; i++) {
		dist[i] = INF;
	}

	for (int i = 1; i <= K; i++) {
		int m, n;
		scanf("%d %d", &m, &n);

		sero[m].emplace_back(n, i);
		garo[n].emplace_back(m, i);
	}
	sero[1].emplace_back(0, 0);		//1,0 ��ǥ���� ���

	sero[M].emplace_back(N, K + 1);	//������
	garo[N].emplace_back(M, K + 1);

	for (int i = 1; i <= K; i++) {	//���� ����� ��ư�� ������ 1�� ���
		graph[i * 2].emplace_back(i * 2 + 1, 1);
		graph[i * 2 + 1].emplace_back(i * 2, 1);
	}

	for (int i = 1; i <= N; i++) {
		sort(garo[i].begin(), garo[i].end());
	}
	for (int i = 1; i <= M; i++) {
		sort(sero[i].begin(), sero[i].end());
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < (int)garo[i].size() - 1; j++) {
			const int dist = garo[i][j + 1].first - garo[i][j].first;
			const int u = garo[i][j + 1].second;
			const int v = garo[i][j].second;
			graph[u * 2].emplace_back(v * 2, dist);		//���� ���� ���� ����
			graph[v * 2].emplace_back(u * 2, dist);
		}
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j < (int)sero[i].size() - 1; j++) {
			const int dist = sero[i][j + 1].first - sero[i][j].first;
			const int u = sero[i][j + 1].second;
			const int v = sero[i][j].second;
			graph[u * 2 + 1].emplace_back(v * 2 + 1, dist);	//���� ���� ���� ����
			graph[v * 2 + 1].emplace_back(u * 2 + 1, dist);
		}
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	pq.push({ -1,1 });
	while (!pq.empty()) {
		const long long curDist = pq.top().first;
		const int curId = pq.top().second;
		pq.pop();

		if (dist[curId] < curDist) continue;

		for (auto& next : graph[curId]) {
			const int nextId = next.first;
			const long long nextDist = next.second;

			if (dist[nextId] > curDist + nextDist) {
				dist[nextId] = curDist + nextDist;
				pq.push({ dist[nextId], nextId });
			}
		}
	}

	if (dist[(K + 1) * 2] == INF && dist[(K + 1) * 2 + 1] == INF) {
		printf("%d", -1);
	}
	else {
		printf("%lld", min(dist[(K + 1) * 2], dist[(K + 1) * 2 + 1]));
	}
}
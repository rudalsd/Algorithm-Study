#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace  std;
int V, E;
vector<int> list[10001];		//그래프 저장할 배열
int id[10001];					//방문할 순서를 저장할 배열
int seq = 1;					//방문한 순서
int fin[10001];					//scc 여부
stack<int> s;
vector<vector<int>> ans;		//scc들을 저장할 배열
int dfs(int cur)
{
	id[cur] = seq++;
	int ret = id[cur];
	s.push(cur);
	for (int i = 0; i < list[cur].size(); i++) {
		int next = list[cur][i];
		if (id[next] == 0) {		//한번도 방문하지 않았다면
			ret = min(ret, dfs(next));	//부모 중 가장 작은 id값을 ret에 저장
		}
		else if (fin[next] == 0) {	//방문했을 때 아직 scc가 아니라면
			ret = min(ret, id[next]);	//부모 중 가장 작은 id값을 ret에 저장
		}
	}
	if (ret == id[cur]) {		//부모 중 가장 작은 id값과 본인의 id값이 일치한다면
		vector<int> scc;
		while (1) {
			int top = s.top();	//stack에서 빼주면서
			fin[top] = 1;
			scc.push_back(top);	//scc에 push
			s.pop();
			if (top == cur) {	//stack에서 본인을 만나면
				break;
			}
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
	return ret;
}
int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (id[i] == 0) dfs(i);
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("-1\n");
	}
}
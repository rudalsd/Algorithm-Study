#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> tickets = { {"ICN", "AOO"}, {"AOO", "BOO"}, {"BOO", "COO"}, {"COO", "DOO"}, {"DOO", "EOO"}, {"EOO", "DOO"}, {"DOO", "COO"}, {"COO", "BOO"}, {"BOO", "AOO"} };
vector<int> visited;
vector<string> path;
vector<string> answer;

void dfs(string cur, int level)
{
	if (level == tickets.size())
	{
		if (path[level] != "")
			answer = path;
		return;
	}
	int flag = 0;
	for (int i = 0; i < tickets.size(); i++)
	{
		if (visited[i] != 1)
		{
			if (cur == tickets[i][0])
			{
				visited[i]++;
				path[level + 1] = tickets[i][1];
				dfs(tickets[i][1], level + 1);
				visited[i]--;
			}
		}
	}
}

int main()
{
	path.resize(tickets.size() + 1);
	visited.resize(tickets.size());
	path[0] = "ICN";
	sort(tickets.begin(), tickets.end());
	dfs("ICN", 0);

	int de = -1;
}
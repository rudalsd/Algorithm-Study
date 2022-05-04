#include<iostream>
#include<vector>

using namespace std;

struct building {
	int time;												//건물을 짓는데 걸리는 시간	
	vector<int> must;										//건물을 짓기 위해 먼저 지어야 하는 건물
};

building list[550];
int dp[550];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> list[i].time;
		while (1) {
			int num;
			cin >> num;
			if (num == -1) {
				break;
			}
			else {
				list[i].must.push_back(num);
			}
		}
	}

	for (int k = 1; k <= N; k++) {									//N개의 건물을 N번 체크
		for (int i = 1; i <= N; i++) {
			int max = 0;
			int flag = 0;
			for (int j = 0; j < list[i].must.size(); j++) {
				if (dp[list[i].must[j]] == 0) {						//선행 건물이 아직 지어지지 않았다면 break
					flag = 1;
					break;
				}
				if (max < dp[list[i].must[j]]) {					//선행 건물 중 가장 늦게 지어지는 건물의 시간을 max에 넣기
					max = dp[list[i].must[j]];
				}
			}
			if (flag == 0) {
				dp[i] = max + list[i].time;							//가장 오래 걸리는 건물 시간과 i번 건물을 짓는데 걸리는 시간을 dp배열에 넣기
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << endl;
	}
}
#include<iostream>
#include<vector>

using namespace std;

struct building {
	int time;												//�ǹ��� ���µ� �ɸ��� �ð�	
	vector<int> must;										//�ǹ��� ���� ���� ���� ����� �ϴ� �ǹ�
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

	for (int k = 1; k <= N; k++) {									//N���� �ǹ��� N�� üũ
		for (int i = 1; i <= N; i++) {
			int max = 0;
			int flag = 0;
			for (int j = 0; j < list[i].must.size(); j++) {
				if (dp[list[i].must[j]] == 0) {						//���� �ǹ��� ���� �������� �ʾҴٸ� break
					flag = 1;
					break;
				}
				if (max < dp[list[i].must[j]]) {					//���� �ǹ� �� ���� �ʰ� �������� �ǹ��� �ð��� max�� �ֱ�
					max = dp[list[i].must[j]];
				}
			}
			if (flag == 0) {
				dp[i] = max + list[i].time;							//���� ���� �ɸ��� �ǹ� �ð��� i�� �ǹ��� ���µ� �ɸ��� �ð��� dp�迭�� �ֱ�
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << endl;
	}
}
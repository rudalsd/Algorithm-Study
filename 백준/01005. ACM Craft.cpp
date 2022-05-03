#include <iostream>
#include <vector>

using namespace std;

int arr[1100];
int dp[1100];
int N, K, X, Y, W;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		vector<int> list[1100];
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			list[i].push_back(0);													//���� �ǹ��� ���� ��츦 ����� 0�� �ǹ��� ��� �ǹ��� �߰�
			dp[i] = -1;																//�ǹ��� ������ ���� ���� �� -1�� �ʱ�ȭ
		}

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			list[Y].push_back(X);													//���� �ǹ��� list�� push
		}

		cin >> W;

		for (int a = 0; a < N; a++) {
			if (dp[W] != -1) break;													//���⸦ ���ϴ� �ǹ��� �������� �� break
			for (int i = 1; i <= N; i++) {
				if (dp[W] != -1) break;
				int max = 0;
				if (dp[i] == -1) {													//�ǹ��� �������� �ʾ��� �� �ǹ��� ������ �ּ� �ð� ���ϱ�
					for (int j = 0; j < list[i].size(); j++) {
						if (dp[list[i][j]] != -1) {
							if (max < dp[list[i][j]]) {								//���� �ʰ� �������� �ǹ��� max�� ����
								max = dp[list[i][j]];
							}
						}
						else {
							max = -1;
							break;
						}
					}
					if (max != -1) {
						dp[i] = max + arr[i];										//���� �ǹ��� ��� �������� �� dp�� �ǹ��� �������� �ð� ����
					}
				}
			}
		}
		cout << dp[W] << endl;
	}
}

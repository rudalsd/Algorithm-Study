#include <iostream>

using namespace std;

int main()
{
	long long N, k;
	cin >> N >> k;

	long long cnt = 0;
	long long start, end, mid, res;
	start = 1;
	end = N * N;
	mid = 0;
	while (start <= end)									//start �� end���� �۰ų� ���� ������ �ݺ�
	{
		mid = (long long)((start + end) / 2);
		cnt = 0;

		for (int i = 1; i <= N; i++) {						//N��° ����� Ž��
			cnt += min(N, (long long)(mid / i));			//mid/i�� mid�� �� ���� ��� ° ���� �ִ��� ��Ÿ���� ��
			if (i > mid) {									//mid���� i�� �� ũ�� Ż��
				break;
			}
		}

		if (cnt < k) {										//cnt�� K���� ������ start�� mid + 1�� ����
			start = mid + 1;
		}
		else {												//cnt�� K���� ũ�ų� ������ end�� mid - 1�� ����
			res = mid;										//cnt�� k���� ũ�ų� ���� ���� ���� �� �� �����Ƿ� res�� mid �� ����
			end = mid - 1;
		}
	}

	cout << res;
}
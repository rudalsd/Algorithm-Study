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
	while (start <= end)									//start 가 end보다 작거나 같을 때까지 반복
	{
		mid = (long long)((start + end) / 2);
		cnt = 0;

		for (int i = 1; i <= N; i++) {						//N번째 행까지 탐색
			cnt += min(N, (long long)(mid / i));			//mid/i는 mid가 그 행의 몇번 째 열에 있는지 나타내는 수
			if (i > mid) {									//mid보다 i가 더 크면 탈출
				break;
			}
		}

		if (cnt < k) {										//cnt가 K보다 작으면 start를 mid + 1로 갱신
			start = mid + 1;
		}
		else {												//cnt가 K보다 크거나 같으면 end를 mid - 1로 갱신
			res = mid;										//cnt가 k보다 크거나 같을 때만 답이 될 수 있으므로 res에 mid 값 대입
			end = mid - 1;
		}
	}

	cout << res;
}
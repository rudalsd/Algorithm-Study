#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> vect;

int binarySearch(int num)									//이분 탐색
{
	int start, end, middle;
	start = 0;
	end = vect.size() - 1;

	while (start <= end)
	{
		middle = (start + end) / 2;

		if (vect[middle] == num) {
			return 1;
		}
		else if (vect[middle] > num) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}

	return 0;
}

int main()
{
	int N, M;

	scanf("%d", &N);										//첫번째 방법

	for (int i = 0; i < N; i++) {							//숫자 입력 받기
		int num;
		scanf("%d", &num);
		vect.push_back(num);
	}

	sort(vect.begin(), vect.end());							//입력 받은 숫자 오름차순 정렬

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {							//이분 탐색 돌리기
		int num;
		scanf("%d", &num);
		printf("%d ", binarySearch(num));
	}

	/*unordered_map<int, int> map;							//두번째 방법
															//unordered_map 생성
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {							//map에 입력 받기
		int num;
		scanf("%d", &num);
		map[num]++;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", (int)map.count(num));					//map에 존재하면 1 출력, 없으면 0 출력
	}*/
}
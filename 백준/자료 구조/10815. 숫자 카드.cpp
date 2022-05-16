#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> vect;

int binarySearch(int num)									//�̺� Ž��
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

	scanf("%d", &N);										//ù��° ���

	for (int i = 0; i < N; i++) {							//���� �Է� �ޱ�
		int num;
		scanf("%d", &num);
		vect.push_back(num);
	}

	sort(vect.begin(), vect.end());							//�Է� ���� ���� �������� ����

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {							//�̺� Ž�� ������
		int num;
		scanf("%d", &num);
		printf("%d ", binarySearch(num));
	}

	/*unordered_map<int, int> map;							//�ι�° ���
															//unordered_map ����
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {							//map�� �Է� �ޱ�
		int num;
		scanf("%d", &num);
		map[num]++;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", (int)map.count(num));					//map�� �����ϸ� 1 ���, ������ 0 ���
	}*/
}
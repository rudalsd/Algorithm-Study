#include<iostream>

using namespace std;

int G, P, g;

int vect[100005];														//���� �� ����Ʈ�� ������ �迭

int find(int num)														//���� �� ����Ʈ�� ã�� �Լ�
{
	if (vect[num] == num) return num;
	return vect[num] = find(vect[num]);
}

int main()
{
	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		vect[i] = i;
	}

	int cnt = 0;

	for (int i = 0; i <= P; i++) {
		scanf("%d", &g);
		int num = find(g);												//���� �� ����Ʈ�� num�� ����
		if (num == 0) {													//num�� 0�̶�� �� ����Ʈ�� ���ٴ� ���̹Ƿ�
			cout << cnt;												//cnt�� ����ϰ� break
			break;
		}
		else if (num == g) {											//num == g��� �� ����Ʈ�̹Ƿ�
			vect[g] = find(g - 1);										//���� ����Ʈ�� ���� ����Ʈ���� �� ����Ʈ�� ã�Ƽ� vect�� ����
		}
		else {															//�� �� �ƴ϶�� ���� ����Ʈ�� �� �ִٴ� ���̹Ƿ�
			int next = find(g - 1);										//�������� ����ִ� ����Ʈ�� next�� �ְ�
			vect[next] = find(next - 1);								//next�� ä�� �� next �������� ��� �ִ� ����Ʈ�� vect�� ����

		}
		cnt++;
	}
}
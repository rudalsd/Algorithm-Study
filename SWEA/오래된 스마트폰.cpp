#include<iostream>

using namespace std;

struct pos {
	int num;
	int cnt;
};

int cal[10];							//������ ������ ����
int num[20];							//�Է� ������ ���� ����
pos Pnum[1100];							//���� �� �ִ� ���ڿ� Ƚ�� ����
int result;								//���� �� �ִ� ����
int DP[1100];							//� ���ڸ� ���� �� �ִ� �ּ����� Ƚ�� �޸����¡
int cnt;								//���� �� �ִ� ������ ��
int N, O, M, W;

void Init();							//�ʱ�ȭ �� �� �Է�
void dp();								//���ڰ� ������ ���� �� ���� dp������
void dfs(int level, int limitlevel);	//���� �� �ִ� ���� ���� �̱�
int pow(int num, int p);				//�������� ���ϱ� ���� �Լ�

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		Init();							//���� �ʱ�ȭ �� �Է�

		for (int i = 1; i <= 3; i++) {
			dfs(0, i);
		}

		if (DP[W] != 99) {								//���� dfs�� ���ؼ� DP�� ���� ����Ǿ��ٸ� �ٷ� ���
			cout << "#" << t << " " << DP[W] << endl;
			continue;
		}
		if (num[0] == 1 && W == 0) {					//0�� �Է��� �� �ְ�, ���ϴ� ���� 0�̸� 1�� ���
			cout << "#" << t << " " << 1 << endl;
			continue;
		}

		dp();

		if (DP[W] + 1 <= M) {								//=�� �Է��ϱ� ���� 1�� �����ش�.
			cout << "#" << t << " " << DP[W] + 1 << endl;
		}
		else {												//�ִ� �Է� Ƚ���� �ʰ��߱� ������ -1 ���
			cout << "#" << t << " " << -1 << endl;
		}
	}
}

void Init()
{
	cnt = 0;
	cin >> N >> O >> M;

	for (int i = 0; i < 10; i++) {				//��� ������ ������ �ʱ�ȭ
		cal[i] = 0;
	}
	for (int i = 0; i < 20; i++) {				//��� ������ ���� �ʱ�ȭ
		num[i] = 0;
	}
	for (int i = 0; i < 1100; i++) {			//���� �� �ִ� ���ڿ� Ƚ�� �ʱ�ȭ
		Pnum[i].num = 0;
		Pnum[i].cnt = 0;
	}
	for (int i = 0; i < 1100; i++) {			//�� ������ ���� �� �ִ� �ּڰ��� �����ؾ� �ϱ� ������ 99�� �ʱ�ȭ
		DP[i] = 99;
	}

	for (int i = 0; i < N; i++) {				//��� ������ ���� �Է�
		int n;
		cin >> n;
		num[n] = 1;
	}
	for (int i = 0; i < O; i++) {				//��� ������ ������ �Է�
		int c;
		cin >> c;
		cal[c] = 1;
	}

	cin >> W;
}

void dp()
{
	while (1) {
		int flag = 0;
		for (int j = 0; j < 1000; j++) {
			for (int i = 0; i < cnt; i++) {
				for (int k = 1; k <= 4; k++) {
					if (cal[k] == 1) {
						if (k == 1) {
							if (j + Pnum[i].num < 1000) {								//������ �� 1000�� ���� �ʰ�, �������� �� Ƚ���� ����� Ƚ������ �� ������ ����
								if (DP[j + Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j + Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else if (k == 2) {
							if (j - Pnum[i].num >= 0) {									//���� �� ������ ���� �ʰ�, �������� �� Ƚ���� ����� Ƚ������ �� ������ ����
								if (DP[j - Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j - Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else if (k == 3) {
							if (j * Pnum[i].num < 1000) {								//������ �� 1000�� ���� �ʰ�, �������� �� Ƚ���� ����� Ƚ������ �� ������ ����
								if (DP[j * Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j * Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else {
							if (Pnum[i].num > 0) {										//0���� ������ �ʰ�, �������� �� Ƚ���� ����� Ƚ������ �� ������ ����
								if (DP[j / Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j / Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
					}
				}
			}
		}
		if (flag == 0) {			//�ѹ��̶� ���ŵ� ���� ������ break
			break;					//������ �ѹ��̶� ������ ��� ����
		}
	}
}

void dfs(int level, int limitlevel)
{
	if (level == limitlevel) {
		Pnum[cnt].num = result;				//�־��� ���ڷ� ���� �� �ִ� ���ڵ��� �迭�� ����
		Pnum[cnt].cnt = limitlevel;			//���ڸ� ���� �� ��ư�� ���� Ƚ��
		DP[result] = limitlevel;			//���� ���� �־ �ּڰ��̱� ������ DP�迭�� ����
		cnt++;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (level == 0 && i == 0) {								//ù ���ڰ� 0�̸� continue
			continue;
		}
		else if (num[i] == 1) {
			result += i * pow(10, (limitlevel - level - 1));
			dfs(level + 1, limitlevel);
			result -= i * pow(10, (limitlevel - level - 1));
		}
	}
}

int pow(int num, int p)								//�������� ���ϱ� ���� �Լ�
{
	if (p == 0) {
		return 1;
	}
	else {
		for (int i = 0; i < p - 1; i++) {
			num *= num;
		}
	}
	return num;
}
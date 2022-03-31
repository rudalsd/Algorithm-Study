#include<iostream>

using namespace std;

struct pos {
	int num;
	int cnt;
};

int cal[10];							//가능한 연산자 저장
int num[20];							//입력 가능한 숫자 저장
pos Pnum[1100];							//만들 수 있는 숫자와 횟수 저장
int result;								//만들 수 있는 숫자
int DP[1100];							//어떤 숫자를 만들 수 있는 최소한의 횟수 메모라이징
int cnt;								//만들 수 있는 숫자의 수
int N, O, M, W;

void Init();							//초기화 및 값 입력
void dp();								//숫자가 변하지 않을 때 까지 dp돌리기
void dfs(int level, int limitlevel);	//만들 수 있는 숫자 순열 뽑기
int pow(int num, int p);				//제곱수를 구하기 위한 함수

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		Init();							//변수 초기화 및 입력

		for (int i = 1; i <= 3; i++) {
			dfs(0, i);
		}

		if (DP[W] != 99) {								//만약 dfs를 통해서 DP에 값이 저장되었다면 바로 출력
			cout << "#" << t << " " << DP[W] << endl;
			continue;
		}
		if (num[0] == 1 && W == 0) {					//0을 입력할 수 있고, 원하는 수가 0이면 1을 출력
			cout << "#" << t << " " << 1 << endl;
			continue;
		}

		dp();

		if (DP[W] + 1 <= M) {								//=을 입력하기 위해 1을 더해준다.
			cout << "#" << t << " " << DP[W] + 1 << endl;
		}
		else {												//최대 입력 횟수를 초과했기 때문에 -1 출력
			cout << "#" << t << " " << -1 << endl;
		}
	}
}

void Init()
{
	cnt = 0;
	cin >> N >> O >> M;

	for (int i = 0; i < 10; i++) {				//사용 가능한 연산자 초기화
		cal[i] = 0;
	}
	for (int i = 0; i < 20; i++) {				//사용 가능한 숫자 초기화
		num[i] = 0;
	}
	for (int i = 0; i < 1100; i++) {			//만들 수 있는 숫자와 횟수 초기화
		Pnum[i].num = 0;
		Pnum[i].cnt = 0;
	}
	for (int i = 0; i < 1100; i++) {			//각 숫자의 만들 수 있는 최솟값을 저장해야 하기 때문에 99로 초기화
		DP[i] = 99;
	}

	for (int i = 0; i < N; i++) {				//사용 가능한 숫자 입력
		int n;
		cin >> n;
		num[n] = 1;
	}
	for (int i = 0; i < O; i++) {				//사용 가능한 연산자 입력
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
							if (j + Pnum[i].num < 1000) {								//더했을 때 1000을 넘지 않고, 연산했을 때 횟수가 저장된 횟수보다 더 작으면 갱신
								if (DP[j + Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j + Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else if (k == 2) {
							if (j - Pnum[i].num >= 0) {									//뺐을 때 음수가 되지 않고, 연산했을 때 횟수가 저장된 횟수보다 더 작으면 갱신
								if (DP[j - Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j - Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else if (k == 3) {
							if (j * Pnum[i].num < 1000) {								//곱했을 때 1000을 넘지 않고, 연산했을 때 횟수가 저장된 횟수보다 더 작으면 갱신
								if (DP[j * Pnum[i].num] > DP[j] + Pnum[i].cnt + 1) {
									DP[j * Pnum[i].num] = DP[j] + Pnum[i].cnt + 1;
									flag = 1;
								}
							}
						}
						else {
							if (Pnum[i].num > 0) {										//0으로 나누지 않고, 연산했을 때 횟수가 저장된 횟수보다 더 작으면 갱신
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
		if (flag == 0) {			//한번이라도 갱신된 적이 없으면 break
			break;					//갱신이 한번이라도 됐으면 계속 진행
		}
	}
}

void dfs(int level, int limitlevel)
{
	if (level == limitlevel) {
		Pnum[cnt].num = result;				//주어진 숫자로 만들 수 있는 숫자들을 배열에 저장
		Pnum[cnt].cnt = limitlevel;			//숫자를 만들 때 버튼을 누른 횟수
		DP[result] = limitlevel;			//무슨 일이 있어도 최솟값이기 때문에 DP배열에 저장
		cnt++;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (level == 0 && i == 0) {								//첫 숫자가 0이면 continue
			continue;
		}
		else if (num[i] == 1) {
			result += i * pow(10, (limitlevel - level - 1));
			dfs(level + 1, limitlevel);
			result -= i * pow(10, (limitlevel - level - 1));
		}
	}
}

int pow(int num, int p)								//제곱수를 구하기 위한 함수
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
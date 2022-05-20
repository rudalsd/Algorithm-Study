#include<iostream>

using namespace std;

int G, P, g;

int vect[100005];														//다음 빈 게이트를 저장할 배열

int find(int num)														//다음 빈 게이트를 찾는 함수
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
		int num = find(g);												//다음 빈 게이트를 num에 저장
		if (num == 0) {													//num이 0이라면 들어갈 게이트가 없다는 뜻이므로
			cout << cnt;												//cnt를 출력하고 break
			break;
		}
		else if (num == g) {											//num == g라면 빈 게이트이므로
			vect[g] = find(g - 1);										//지금 게이트의 다음 게이트부터 빈 게이트를 찾아서 vect에 저장
		}
		else {															//둘 다 아니라면 지금 게이트가 차 있다는 뜻이므로
			int next = find(g - 1);										//다음으로 비어있는 게이트를 next에 넣고
			vect[next] = find(next - 1);								//next를 채운 후 next 다음으로 비어 있는 게이트를 vect에 저장

		}
		cnt++;
	}
}
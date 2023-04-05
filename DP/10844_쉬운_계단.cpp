#include<iostream>
using namespace std;

int N;
int DP[101][10];

void Init() {

	//길이가 1인 계단 수 초기화
	DP[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}

	
	//길이가 2 - 100 인 계단 수 초기화
	for (int i = 2; i <= 100; i++) {

		for (int j = 0; j <= 9; j++) {

			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1] % 1000000000;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}

		}

	}

}





int main() {

	Init();

	cin >> N;
	long long total = 0;
	for (int i = 0; i <= 9; i++) {
		total += DP[N][i];
		//cout << DP[N][i] << ' ';
	}
	//cout << endl;
	cout << (total % 1000000000) << endl;

}
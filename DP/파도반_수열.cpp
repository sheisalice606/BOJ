#include<iostream>
using namespace std;

int T, N;
int DP[101];
// i 번째 삼각형의 변의 길이 -> DP[i] = N


void Wave() {

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;
	for (int i = 6; i <= 100; i++) {
		DP[i] = DP[i - 1] + DP[i - 5];
	}

}



int main() {

	cin >> T;
	Wave();

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << DP[N] << endl;
	}

}
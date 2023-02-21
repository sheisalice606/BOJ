#include <iostream>
#include <vector>
using namespace std;

int N;
int map[1001];
int dp[1001];
int ans = 0;


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
}

/*
중요 포인트 : 초기 값을 설정한다. -> 자신만 포함시켜도 길이 1 이 보장된다. -> dp[n] = 1
	1. 자신 이전의 값들을 탐색한다.
	2. 그 중에서 자신보다 큰 값들을 탐색한다. (그래야 유의미한 값 갱신이 이루어진다.)
	3. 반복문을 통해 갱신한다.
*/

void solve() {
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= n; i++) {
			if (map[i] > map[n]) {
				if (dp[i] + 1 > dp[n]) {
					dp[n] = dp[i] + 1;
				}
			}
		}
		ans = max(ans, dp[n]);
	}
}



int main() {

	input();
	solve();
	cout << ans << endl;

}
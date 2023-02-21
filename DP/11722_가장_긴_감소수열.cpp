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
�߿� ����Ʈ : �ʱ� ���� �����Ѵ�. -> �ڽŸ� ���Խ��ѵ� ���� 1 �� ����ȴ�. -> dp[n] = 1
	1. �ڽ� ������ ������ Ž���Ѵ�.
	2. �� �߿��� �ڽź��� ū ������ Ž���Ѵ�. (�׷��� ���ǹ��� �� ������ �̷������.)
	3. �ݺ����� ���� �����Ѵ�.
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
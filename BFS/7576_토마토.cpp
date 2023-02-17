#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int map[1001][1001];
int visit[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
int unRippen = 0;
int result = 0;

bool bfs() {


	while (!q.empty()) {

		int sz = q.size();

		for (int n = 0; n < sz; n++) {

			int px = q.front().first;
			int py = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {

				int nx = px + dx[i];
				int ny = py + dy[i];

				if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
					if (!visit[nx][ny]) {

						visit[nx][ny] = 1;
						q.push({ nx, ny });

					}
				}

			}

		}

		result++;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visit[i][j]) {
				return false;
			}
		}
	}

	return true;

}



int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (!map[i][j]) {
				unRippen++;
			}
			if (map[i][j] == -1) {
				visit[i][j] = 1;
			}
			if (map[i][j] == 1) {
				visit[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	if (!unRippen) {
		cout << 0 << endl;
	}
	else {
		if (bfs()) {
			cout << result - 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

}
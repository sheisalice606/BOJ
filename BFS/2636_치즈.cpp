#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[101][101];
int visit[101][101];
bool map_melt[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

void melting() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map_melt[i][j]) {
				map[i][j] = 0;
			}
		}
	}
}


void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
			if (!visit[nx][ny]) {
				if (!map[nx][ny]) { // 다음 경로 : 공기
					visit[nx][ny] = 1;
					dfs(nx, ny);
				}
				else { // 다음 경로 : 치즈
					visit[nx][ny] = 1;
					map_melt[nx][ny] = true;
				}
			}
		}
	}

}





int main() {

	int cheeze = 0;
	int result = 0;
	int time = 0;
	input();


	while (true) {

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j]) {
					cheeze++;
				}
			}
		}



		if (!cheeze) {
			cout << time << endl;
			cout << result << endl;
			break;
		}
		else {




			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (!map[i][j]) {
						dfs(i, j);
						goto complete;
						// 최초 dfs 실행 후 빠져나오기
					}
				}
			}
			complete:







			melting(); 
			time++;
			result = cheeze;






			// 초기화
			cheeze = 0;
			memset(visit, 0, sizeof(visit));
			memset(map_melt, false, sizeof(map_melt));

		}

	}

}
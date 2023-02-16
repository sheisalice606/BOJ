#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[301][301];

int map_melt[301][301]; // 초기화 대상
int visit[301][301]; // 초기화 대상

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

bool all_melt_check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] > 0) {
				// 얼음 하나라도 남아있으면
				return false;
			}
		}
	}

	// 얼음이 모두 녹은 경우
	return true;
}

void melt() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] -= map_melt[i][j];
		}
	}
}


void melting(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
			if (map[nx][ny] <= 0) { // 내딛은 칸이 바다(0) 인 경우
				map_melt[x][y]++;
				// 내딛기 전의 칸의 녹일 양
			}
		}
	}

}


void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
			if (!visit[nx][ny] && map[nx][ny] > 0) {
				visit[nx][ny] = 1;
				dfs(nx, ny);
			}
		}

	}

}

void clear() {

	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map_melt[i][j] = 0;
		}
	}

}



int main() {

	int count = 0;
	int time = 0;
	input();
	

	while (true) {


		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] > 0) {
					// 아직 얼음이 남아있는 칸의 경우
					melting(i, j);
				}
			}
		}





		melt();
		time++;





		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visit[i][j] && map[i][j] > 0) {
					visit[i][j] = 1;
					dfs(i, j);
					count++;
				}
			}
		}




		if (count > 1) {
			// 빙하가 둘 이상으로 갈라진 순간
			cout << time << endl;
			break;
		}


		if (all_melt_check()) {
			// 빙하가 모두 녹은 순간
			cout << 0 << endl;
			break;
		}




		clear();
		count = 0;

	}

}


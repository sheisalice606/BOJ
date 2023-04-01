#include<iostream>
#include<queue>
using namespace std;

// 혼자 풀이 : 90분 -> 반례 케이스 포함한 예시 통과, but 메모리 초과


int R, C;

char map[1001][1001];
int visit[1001][1001];

int fired[1001][1001];
queue<pair<int, int>> fired_queue;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


struct jhoon {
	int x;
	int y;
};
queue<jhoon> q;


void Input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];

			// 지훈의 초기 위치.
			if (map[i][j] == 'J') {
				visit[i][j] = 1;
				q.push({ i, j });
			}

			// 불
			if (map[i][j] == 'F') {
				fired_queue.push({ i, j });
				fired[i][j] = 1;
			}

		}
	}
}


void Fire() {

	int sz = fired_queue.size();
	// 새로 들어온 불타는 영역 좌표, 중복 X

	while (sz > 0) {

		int px = fired_queue.front().first;
		int py = fired_queue.front().second;
		fired_queue.pop();

		for (int i = 0; i < 4; i++) {

			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > R || ny > C) continue;						// 범위 밖을 벗어남.
			if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue;					// 벽 & 불

			fired[nx][ny] = 1;
			fired_queue.push({ nx, ny });

		}

		sz--;
	}

}



int Bfs() {

	int time = 0;

	while (!q.empty()) {

		int sz = q.size();

		for (int n = 0; n < sz; n++) {

			int px = q.front().x;
			int py = q.front().y;
			q.pop();

			// 탈출 ex) 시작부터 탈출 위치인 경우, 0을 반환한다.
			if (px == 1 || px == R) return (time + 1);
			if (py == 1 || px == C) return (time + 1);


			// 1. 불 번짐
			Fire();


			// 2. 지훈이의 이동
			for (int i = 0; i < 4; i++) {
				int nx = px + dx[i];
				int ny = py + dy[i];

				if (nx < 1 || ny < 1 || nx > R || ny > C) continue;		//범위 초과
				if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue; // 벽 & 불
				if (visit[nx][ny] == 1 || fired[nx][ny] == 1) continue; // 이미 방문한 노드 & 불 번짐 노드

				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}

		}

		time++;

	}

	//탈출 실패한 경우
	return -1;

}




int main() {

	Input();

	int ans;
	ans = Bfs();


	if (ans == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans << endl;
	}

}


#include<iostream>
#include<queue>
using namespace std;

int N, M;
int T;

int map[101][101];
int visit[101][101][2]; // 0 -> °Ë ¾øÀ½ , 1 -> °Ë ÀÖÀ½

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct node {
	int x;
	int y;
	int time; // ÇöÀç ½Ã°¢
	bool sword; // Ä® È¹µæ -> true, Ä® ¹ÌÈ¹µæ -> false
};

queue<node> q;


void input() {

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

}


void bfs() {

	q.push({ 1, 1, 0, false }); // init data
	visit[1][1][0] = 1;

	while (!q.empty()) {

		int px = q.front().x;
		int py = q.front().y;
		int time = q.front().time;
		bool state = q.front().sword;
		q.pop();


		if (time > T) {
			// timeover Ã¼Å©
			cout << "Fail" << endl;
			return;
		}


		if (px == N && py == M) {
			cout << time << endl;
			return;
		}



		for (int i = 0; i < 4; i++) {

			int nx = px + dx[i];
			int ny = py + dy[i];
			
			
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue; // ¹üÀ§ Ã¼Å©

			
			if (state == true ) {
				if (visit[nx][ny][1] == 0) {
					visit[nx][ny][1] = 1;
					q.push({ nx, ny, time + 1, true });
				}
			}
			else {

				if (map[nx][ny] == 2 && visit[nx][ny][0] == 0) {
					visit[nx][ny][0] = 1;
					q.push({ nx, ny, time + 1, true });
				}
				else if (map[nx][ny] == 0 && visit[nx][ny][0] == 0) {
					visit[nx][ny][0] = 1;
					q.push({ nx, ny, time + 1, false });
				}

			}

		}



	}

	cout << "Fail" << endl;
	return;

}


int main() {

	input();
	bfs();

}
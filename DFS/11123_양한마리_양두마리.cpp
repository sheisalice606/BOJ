#include <iostream>
using namespace std;

int T;
int H, W;

char map[101][101];
int visit[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;


void Input() {

	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}

}

void Clear() {
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	cnt = 0;
}

void Dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];


		if (nx < 1 || ny < 1 || nx > H || ny > W) continue;
		if (visit[nx][ny] == 1 || map[nx][ny] != '#') continue;

		visit[nx][ny] = 1;
		Dfs(nx, ny);
	}

}

int main() {

	cin >> T;
	for (int n = 1; n <= T; n++) {

		Input();
		
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (map[i][j] == '#' && visit[i][j] == 0) {
					visit[i][j] = 1;
					cnt++;
					Dfs(i, j);
				}
			}
		}
		
		cout << cnt << '\n';
		Clear();

	}


}

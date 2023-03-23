#include<iostream>
using namespace std;


int N, M;
int map[1001][1001];
int visit[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool escape = false;


void input() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		
		string str;
		cin >> str;
		// 0010010

		for (int j = 0; j < N; j++) {
			map[i][j + 1] = str[j] - '0';
		}
		// 0 0 1 0 0 1 0
	}
}


void dfs(int px, int py) {

	for (int i = 0; i < 4; i++) {
		int nx = px + dx[i];
		int ny = py + dy[i];

		if (map[nx][ny] == 0 && visit[nx][ny] == 0 && nx > 0 && ny > 0 && nx <= M && ny <= N) {
			visit[nx][ny] = 1;
			dfs(nx, ny);
		}

	}

}


int main() {

	input();

	for (int i = 1; i <= N; i++) {
		if (map[1][i] == 0) {
			visit[1][i] = 1;
			dfs(1, i);
		}
	}


	for (int i = 1; i <= N; i++) {
		if (visit[M][i] == 1) {
			escape = true;
		}
	}

	if (escape) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}
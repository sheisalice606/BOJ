#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, K, S;
int map[201][201];
int visit[201][201];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, pair<int, int>>> v;

// K(바이러스 타입), <x좌표, y좌표> 

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) { 
				// 바이러스가 들어있는 칸
				visit[i][j] = 1;
				v.push_back({ map[i][j], {i, j} });
			}
		}
	}
	sort(v.begin(), v.end());
	// 오름차순 정렬
}


void bfs(int count) {

	int time = 0;

	while (!v.empty()) {

		if (time == count) {
			return;
		}

		int sz = v.size();

		for (int q = 0; q < sz; q++) {

			int px = v.front().second.first;
			int py = v.front().second.second;
			int virus = v.front().first;
			v.erase(v.begin());
			// 바이러스가 낮은 번호순 부터 pop 된다.


			for (int i = 0; i < 4; i++) {

				int nx = px + dx[i];
				int ny = py + dy[i];

				if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
					if (!visit[nx][ny] && !map[nx][ny]) {
						visit[nx][ny] = 1;
						map[nx][ny] = virus;
						v.push_back({ virus, {nx, ny} });
					}
				}

			}

		}

		sort(v.begin(), v.end());
		time++;
	}

}



int main() {

	int X, Y;
	input();

	cin >> S >> X >> Y;
	bfs(S);

	cout << map[X][Y] << endl;

}
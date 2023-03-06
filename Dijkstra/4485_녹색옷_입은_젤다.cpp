#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 987654321

int N;
int map[125][125];
int dist[125][125];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };



void dijkstra() {

	priority_queue < pair<int, pair<int, int>>> pq;

	dist[0][0] = map[0][0];
	pq.push({ -map[0][0], {0, 0}});

	while (!pq.empty()) {

		int p_dist = -pq.top().first;
		int px = pq.top().second.first;
		int py = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				int n_dist = p_dist + map[nx][ny];

				if (dist[nx][ny] > n_dist) {
					dist[nx][ny] = n_dist;
					pq.push({ -n_dist, {nx, ny} });
				}
			}

		}

	}

}


void clear() {

	memset(map, 0, sizeof(map));
	for (int i = 0; i < 125; i++) {
		for (int j = 0; j < 125; j++) {
			dist[i][j] = INF;
		}
	}
}


int main() {

	int nth = 1;

	while (true) {

		cin >> N;
		if (!N) {
			break;
		}
		else {

			clear(); // 체크 배열 초기화

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cin >> map[i][j];
				}
			}

		
			dijkstra();
			    

			cout << "Problem " << nth << ": " << dist[N - 1][N - 1] << endl;
			
			nth++;

		}

	}
	
}
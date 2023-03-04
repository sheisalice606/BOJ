#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 987654321

int N, M, K, X;
vector<pair<int, int>> v[300001]; // cost, to
priority_queue<pair<int, int>> pq; // cost, to
int dist[300001];




void dijkstra(int start) {

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int p_dist = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < p_dist) {
			// 이미 더 짧은 경우가 있는 경우
			continue;
		}

		for (int i = 0; i < v[current].size(); i++) {

			int n_dist = p_dist + 1;
			int next = v[current][i].second;

			if (dist[next] > n_dist) {
				dist[next] = n_dist;
				pq.push({ -n_dist, next });
			}

		}

	}

}


void input() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back({1, to}); // cost, to
	}
}



int main() {

	int cnt = 0;

	input();
	for (int i = 1; i <= N; i++) { dist[i] = MAX; }

	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << endl;
			cnt++;
		}
	}

	if (!cnt) {
		cout << -1 << endl;
	}
}

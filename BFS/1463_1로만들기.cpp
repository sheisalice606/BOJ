#include<iostream>
#include<queue>
using namespace std;

int N;
queue<pair<int, int>> Q; // N, time

void Input() {
	cin >> N;
	Q.push({ N, 0 });
}

void Bfs() {

	while (!Q.empty()) {

		int curr = Q.front().first;
		int time = Q.front().second;
		Q.pop();

		if (curr == 1) {
			cout << time << endl;
			return;
		}


		if (curr % 3 == 0) {
			Q.push({ (curr / 3), time + 1 });
		}

		if (curr % 2 == 0) {
			Q.push({ (curr / 2), time + 1 });
		}

		Q.push({ curr - 1, time + 1 });

	}

	return;
}


int main() {

	Input();
	Bfs();

}
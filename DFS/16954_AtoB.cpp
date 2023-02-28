#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long A, B;
int cnt;
queue<long long> q;

int bfs() {

	while (!q.empty()) {

		int sz = q.size();

		for (int n = 0; n < sz; n++) {

			long long current = q.front();
			q.pop();

			if (current == B) {
				return cnt + 1;
			}

			long long next_A = current * 2;
			if (next_A <= B) {
				q.push(next_A);
			}


			long long next_B = current * 10 + 1;
			if (next_B <= B) {
				q.push(next_B);
			}

		}

		cnt++;

	}

	return -1;

}




int main() {
	cin >> A >> B;
	q.push(A);
	cout << bfs() << endl;
}
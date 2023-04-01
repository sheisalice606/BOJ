#include<iostream>
#include<queue>
using namespace std;

// ȥ�� Ǯ�� : 90�� -> �ݷ� ���̽� ������ ���� ���, but �޸� �ʰ�


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

			// ������ �ʱ� ��ġ.
			if (map[i][j] == 'J') {
				visit[i][j] = 1;
				q.push({ i, j });
			}

			// ��
			if (map[i][j] == 'F') {
				fired_queue.push({ i, j });
				fired[i][j] = 1;
			}

		}
	}
}


void Fire() {

	int sz = fired_queue.size();
	// ���� ���� ��Ÿ�� ���� ��ǥ, �ߺ� X

	while (sz > 0) {

		int px = fired_queue.front().first;
		int py = fired_queue.front().second;
		fired_queue.pop();

		for (int i = 0; i < 4; i++) {

			int nx = px + dx[i];
			int ny = py + dy[i];

			if (nx < 1 || ny < 1 || nx > R || ny > C) continue;						// ���� ���� ���.
			if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue;					// �� & ��

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

			// Ż�� ex) ���ۺ��� Ż�� ��ġ�� ���, 0�� ��ȯ�Ѵ�.
			if (px == 1 || px == R) return (time + 1);
			if (py == 1 || px == C) return (time + 1);


			// 1. �� ����
			Fire();


			// 2. �������� �̵�
			for (int i = 0; i < 4; i++) {
				int nx = px + dx[i];
				int ny = py + dy[i];

				if (nx < 1 || ny < 1 || nx > R || ny > C) continue;		//���� �ʰ�
				if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue; // �� & ��
				if (visit[nx][ny] == 1 || fired[nx][ny] == 1) continue; // �̹� �湮�� ��� & �� ���� ���

				visit[nx][ny] = 1;
				q.push({ nx, ny });
			}

		}

		time++;

	}

	//Ż�� ������ ���
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


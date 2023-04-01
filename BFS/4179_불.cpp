#include<iostream>
#include<queue>
using namespace std;
#define MAX 987654321

int R, C;
char Map[1001][1001];
int Visit[1001][1001];
// ���� �湮 ����

int Fired[1001][1001];
int Fired_Visit[1001][1001];
// ���� ����

int Dx[4] = { 1, -1, 0, 0 };
int Dy[4] = { 0, 0, 1, -1 };


struct fire {
	int x;
	int y;
	int time;
};
queue<fire> Fire_Q;


struct jhoon {
	int x;
	int y;
	int time;
};
queue<jhoon> Q;


// �Է� ���� �޴´�.
void Input() {

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> Map[i][j];
			Fired[i][j] = MAX;

			if (Map[i][j] == 'F') {
				// ���� Ÿ�� : 0
				Fired_Visit[i][j] = 1;
				Fired[i][j] = 0;
				Fire_Q.push({ i, j, 0 });
			}

			if (Map[i][j] == 'J') {
				Visit[i][j] = 1;
				// ���� Ÿ�� : 0
				Q.push({ i, j, 0 });
			}

		}
	}

}



// ���� ������ �ϼ��Ѵ�.
void Fire_Spread() {

	while (!Fire_Q.empty()) {

		int px = Fire_Q.front().x;
		int py = Fire_Q.front().y;
		int time = Fire_Q.front().time;
		Fire_Q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = px + Dx[i];
			int ny = py + Dy[i];

			if (nx < 1 || ny < 1 || nx > R || ny > C) continue;				// ���� �ʰ�
			if (Map[nx][ny] == '#' || Fired_Visit[nx][ny] == 1) continue;	// ��

			Fired_Visit[nx][ny] = 1;
			Fired[nx][ny] = Fired[px][py] + 1;
			Fire_Q.push({ nx, ny, time + 1 });

		}

	}

}



// �������� �̵�
int Bfs() {

	while (!Q.empty()) {

		int px = Q.front().x;
		int py = Q.front().y;
		int time = Q.front().time;
		// ���� �ð� : 0 
		Q.pop();


		if (px == 1 || px == R) return (time + 1);
		if (py == 1 || py == C) return (time + 1);
		// Ż�� ����

		for (int i = 0; i < 4; i++) {

			int nx = px + Dx[i];
			int ny = py + Dy[i];
			int nTime = time + 1;

			if (nx < 1 || ny < 1 || nx > R || ny > C) continue;				// ���� �ʰ�
			if (Map[nx][ny] == '#' || Map[nx][ny] == 'F') continue;			// �� & ��
			if (Visit[nx][ny] == 1) continue;								// �湮 ��� & �ҿ� ź ���

			if (nTime < Fired[nx][ny]) {
				Visit[nx][ny] = 1;
				Q.push({ nx, ny, nTime });
			}
		}

	}
	
	return -1;

}



int main() {

	Input();
	Fire_Spread();
	int ans = Bfs();
	if (ans == -1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans << endl;
	}

}
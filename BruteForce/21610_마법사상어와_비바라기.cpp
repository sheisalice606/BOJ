#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[51][51];

int cloud[51][51];

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int Water_Copy_Dx[4] = { -1, -1, 1, 1 };
int Water_Copy_Dy[4] = { 1, -1, 1, -1 };


struct moveTo {

	int direct;
	int dist;

};		
// ����, �Ÿ�����
queue<moveTo> q;
vector<pair<int, int>> v;


int Final_Sum() {
	// ��� �̵��� ������, �ٱ��Ͽ� �� ���� �ѷ�
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}



void Input() {

	// N, M �Է�
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// ����, �Ÿ�����
	int direct, dist;
	for (int i = 1; i <= M; i++) {
		cin >> direct >> dist;
		q.push({ direct, dist });
	}


}


void Init_Cloud() {

	cloud[N][1] = 1;
	cloud[N][2] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 1][2] = 1;

	v.push_back({ N, 1 });
	v.push_back({ N, 2 });
	v.push_back({ N - 1, 1 });
	v.push_back({ N - 1, 2 });

}



// x �� 1�� �����Ѵ�. ���� �̵��� ���� �ٷ� ������ �´� ��ǥ�� �����Ѵ�.
int Make_Range(int x) {

	if (x > N) {
		return 1;
	}
	else if (x < 1) {
		return N;
	}
	else {
		return x;
	}

}




// ������ ������ -> �� ���� -> ������ �����
void Move_And_Rain(int direct, int dist) {


	memset(cloud, 0, sizeof(cloud));
	// ���� ������ ��ġ���� �ʱ�ȭ.

	for (int k = 0; k < v.size(); k++) {

		int nx = v[k].first;
		int ny = v[k].second;

		int x_move = dx[direct]; // x ���� �̵� ��
		int y_move = dy[direct]; // y ���� �̵� ��

		for (int n = 0; n < dist; n++) {

			nx += x_move;
			nx = Make_Range(nx);
			// ��� ��ǥ ����

			ny += y_move;
			ny = Make_Range(ny);
			// ��� ��ǥ ����

		}

		v[k].first = nx;
		v[k].second = ny;
		// ���� �� �� �̵� �Ϸ�

	}


	for (int k = 0; k < v.size(); k++) {

		int x = v[k].first;
		int y = v[k].second;

		map[x][y]++; // ������ �̵��� ��ǥ���� �� ������.
		cloud[x][y] = 1; // ������ ���Ӱ� �̵��� ��ǥ�� ǥ����.

	}

}



// ���� ������ ĭ(������ ���Ӱ� �̵��� ��ǥ) �� ������ ������ ����
void Copy_Water() {

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		for (int k = 0; k < 4; k++) {

			int nx = x + Water_Copy_Dx[k];
			int ny = y + Water_Copy_Dy[k];

			if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if (map[nx][ny] >= 1) map[x][y]++;

		}
	}

	v.clear();
	// ���� ����� �ʱ�ȭ.
}


// ���� ���� 2 �̻��� ĭ�� ������ ������, ���� ���� 2 �پ��, moveAndRain ���� ������ ����� ĭ�� �ƴϿ��� ��.
void Create_Cloud() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (map[i][j] >= 2 && cloud[i][j] == 0) {

				cloud[i][j] = 1;
				v.push_back({ i, j });
				map[i][j] -= 2;
				
			}

		}
	}

}



int main() {

	Input();
	Init_Cloud();

	while (!q.empty()) {

		int direct = q.front().direct;
		int dist = q.front().dist;
		q.pop();

		Move_And_Rain(direct, dist);
		Copy_Water();
		Create_Cloud();

	}

	cout << Final_Sum() << endl;

}



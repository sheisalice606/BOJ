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
// 방향, 거리정보
queue<moveTo> q;
vector<pair<int, int>> v;


int Final_Sum() {
	// 모든 이동이 끝나고, 바구니에 든 물의 총량
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}



void Input() {

	// N, M 입력
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// 방향, 거리정보
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



// x 는 1씩 증감한다. 따라서 이동한 순간 바로 범위에 맞는 좌표로 수정한다.
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




// 구름이 움직임 -> 비가 내림 -> 구름이 사라짐
void Move_And_Rain(int direct, int dist) {


	memset(cloud, 0, sizeof(cloud));
	// 기존 구름의 위치정보 초기화.

	for (int k = 0; k < v.size(); k++) {

		int nx = v[k].first;
		int ny = v[k].second;

		int x_move = dx[direct]; // x 단위 이동 값
		int y_move = dy[direct]; // y 단위 이동 값

		for (int n = 0; n < dist; n++) {

			nx += x_move;
			nx = Make_Range(nx);
			// 즉시 좌표 정비

			ny += y_move;
			ny = Make_Range(ny);
			// 즉시 좌표 정비

		}

		v[k].first = nx;
		v[k].second = ny;
		// 구름 한 점 이동 완료

	}


	for (int k = 0; k < v.size(); k++) {

		int x = v[k].first;
		int y = v[k].second;

		map[x][y]++; // 구름이 이동한 좌표에서 비가 내린다.
		cloud[x][y] = 1; // 구름이 새롭게 이동한 좌표를 표기함.

	}

}



// 물이 증가한 칸(구름이 새롭게 이동한 좌표) 에 물복사 마법을 시전
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
	// 구름 저장소 초기화.
}


// 물의 양이 2 이상인 칸에 구름이 생성됨, 물의 양이 2 줄어듬, moveAndRain 에서 구름이 사라진 칸이 아니여야 함.
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



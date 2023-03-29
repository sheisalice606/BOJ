#include<iostream>
#include<vector>
using namespace std;

int T, N;
int map[100001];
int visit[100001];
int check[100001];
int member = 0;


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
}

void clear() {

	member = 0;
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	memset(check, 0, sizeof(check));

}


void dfs(int start) {
	
	int next = map[start];

	if (visit[next] == 0) {
		visit[next] = 1;
		dfs(next);
	}
	else if (check[next] == 0) { // �̹� �湮�� �Ͽ�����, ����Ŭ ���� Ȯ���� �ȵ� ���

		for (int i = next; i != start; i = map[i]) {
			member++; // ���� ���� ����Ŭ ��� �� ī��Ʈ
		}
		member++; // ���� ī��Ʈ

	}

	check[start] = 1;

}


int main() {

	cin >> T;

	while (T > 0) {

		input();

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i);
			}
		}

		cout << N - member << '\n';

		clear();
		T--;
	}

	return 0;

}
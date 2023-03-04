#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

vector<pair<int, int>> ans;
vector<int> v[10001]; // 간선 정보
int visit[10001];
int N, M;

int cnt = 1; // 첫 해킹 컴퓨터를 포함 -> 1


void dfs(int start) {
	for (int i = 0; i < v[start].size(); i++) {

		int next = v[start][i];

		if (!visit[next]) {
			visit[next] = 1;
			cnt++;
			dfs(next);
		}
	}
}


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[B].push_back(A); // B를 해킹하면 A를 해킹할 수 있다.
	}
}


void clear() {
	cnt = 1;
	memset(visit, 0, sizeof(visit));
}


void solve(int top) {
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].second == top) {
			cout << ans[i].first << " ";
		}
	}
}


int main() {

	int top = 0;
	input();


	for (int i = 1; i <= N; i++) {
		visit[i] = 1;
		dfs(i);
		top = max(top, cnt);
		ans.push_back({ i, cnt }); // i, cnt
		clear();
	}

	sort(ans.begin(), ans.end());
	solve(top);
	

}
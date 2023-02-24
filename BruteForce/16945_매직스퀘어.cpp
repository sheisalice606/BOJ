#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 987654321

vector<int> origin;
vector<int> v;
int ans = MAX;

bool check() { // 매직 스퀘어 : return true

	int sum = v[0] + v[1] + v[2];

	if (v[3] + v[4] + v[5] != sum) {
		return false;
	}
	if (v[6] + v[7] + v[8] != sum) {
		return false;
	}
	if (v[0] + v[3] + v[6] != sum) {
		return false;
	}
	if (v[1] + v[4] + v[7] != sum) {
		return false;
	}
	if (v[2] + v[5] + v[8] != sum) {
		return false;
	}
	if (v[0] + v[4] + v[8] != sum) {
		return false;
	}
	if (v[2] + v[4] + v[6] != sum) {
		return false;
	}
	return true;

}

void input() {
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		origin.push_back(num);
	}

	for (int i = 0; i < 9; i++) {
		v.push_back(i + 1);
		// 1234...789
	}
}




int main() {

	
	input();
	

	do {

		int gap = 0;

		if (check()) { // 순열 조합을 진행하다가 매직스퀘어가 생성된 경우

			for (int i = 0; i < 9; i++) {
				gap += abs(origin[i] - v[i]);
			}

			ans = min(ans, gap);
		}
		


	} while (next_permutation(v.begin(), v.end())); // 모든 순열조합 생성 1234..9 -> 9876..1 까지


	cout << ans << endl;


}
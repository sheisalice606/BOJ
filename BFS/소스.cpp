#include<iostream>
using namespace std;

int T, N;
int map[1000001];

void Input() {

	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}

}

int Profit() {

	int total = 0;

	for (int i = 1; i <= N; i++) {
		if (map[i] < map[i + 1]) {
			total -= map[i];
			//±¸¸Å
		}
		if (map[i] > map[i + 1]) {

		}
		
	}

}


int main() {

	cin >> T;
	for (int i = 1; i <= T; i++) {
		Input();

	}


}
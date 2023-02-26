/*BOJ_)14889번 스타트와 링크
		b_d_o_o		*/
#include <iostream>
using namespace std;
int checkCnt;
int matrix[20][20];
int N;
int table[20];
int result = 987654321;
void startTeam(int p);
void score();
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			int n;
			cin >> n;
			matrix[i][j] = n;
		}
	}
	startTeam(0);
	cout << result;
}

void startTeam(int p) {
	if (checkCnt == N / 2) {
		score();
		return;
	}
	for (int i = p;i < N;i++) {
		if (table[i] == 0) {
			table[i] = 1;
			checkCnt++;
			startTeam(i + 1);
			checkCnt--;
			table[i] = 0;
		}
		if (result == 0) {
			return;
		}
	}
}
void score() {
	int s = 0;
	int l = 0;
	int S = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (table[i] == 1 && table[j] == 1) {
				s += matrix[i][j];
			}
			if (table[i] == 0 && table[j] == 0) {
				l += matrix[i][j];
			}
		}
	}
	S = abs(s - l);
	if (result > S) {
		result = S;
	}
}
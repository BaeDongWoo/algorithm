/*BOJ_)종이의 갯수
	 b_d_o_o	*/
#include <iostream>
using namespace std;
int arr[2200][2200];
int minusCnt;
int zeroCnt;
int oneCnt;
void comp(int a, int b, int start);
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	comp(0, 0, N);
	cout << minusCnt << '\n' << zeroCnt << '\n' << oneCnt << '\n';
	return 0;
}

void comp(int a, int b, int start) {
	int first = arr[a][b];
	bool check = 1;

	for (int i = a;i < a+start;i++) {
		for (int j = b;j < b+start;j++) {
			if (arr[i][j] != first) {
				check = 0;
				break;
			}
		}
	}
	if (check == 1) {
		if (first == -1) {
			minusCnt++;
		}
		else if (first == 0) {
			zeroCnt++;
		}
		else if (first == 1) {
			oneCnt++;
		}
	}
	else {
		for (int i = a;i < a + start;i + start / 3) {
			for (int j = b;j < b + start;j + start / 3) {
				comp(i, j, start / 3);
			}
		}
	}
}
/*BOJ_)1149번 RGB거리
		b_d_o_o		*/
#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1001;
int houseRGBCost[MAXN][3];
int main() {
	int N;
	cin >> N;
	for (int house = 0;house < N;house++) {
		for (int cost = 0;cost < 3;cost++) {
			cin >> houseRGBCost[house][cost];//0은 빨강 1은 초록 2는 파랑의 가격
		}
	}
	int RGBCost[MAXN][3] = { {0,} };
	RGBCost[0][0] = houseRGBCost[0][0];
	RGBCost[0][1] = houseRGBCost[0][1];
	RGBCost[0][2] = houseRGBCost[0][2];
	for (int i = 1;i < N;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				if (j != k) {
					if (RGBCost[i][k] == 0) {
						RGBCost[i][k] = RGBCost[i - 1][j] + houseRGBCost[i][k];
					}
					else {
						int newCost= RGBCost[i - 1][j] + houseRGBCost[i][k];
						RGBCost[i][k] = min(RGBCost[i][k], newCost);
					}
				}
			}
		}
	}
	int result = 987654321;
	for (int i = 0;i < 3;i++) {
		result = min(result, RGBCost[N - 1][i]);
	}
	cout << result;
	return 0;
}
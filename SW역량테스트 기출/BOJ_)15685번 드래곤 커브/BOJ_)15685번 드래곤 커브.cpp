/*BOJ_)15685번 드래곤 커브
		b_d_o_o			*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAXN = 10000;
bool check[101][101];
vector<pair<int, int>> v;
int endx;
int endy;
void curve();
int main() {
	int N;
	cin >> N;
	while (N--) {
		v.clear();
		endx = 0;
		endy = 0;
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		int firstX = x;
		int firstY = y;
		v.push_back(make_pair(x, y));
		int endX;
		int endY;
		if (d == 0) {//0세대의 좌표
			endX = firstX + 1;
			endY = firstY;
		}
		else if (d == 1) {
			endX = firstX;
			endY = firstY - 1;
		}
		else if (d == 2) {
			endX = firstX - 1;
			endY = firstY;
		}
		else {
			endX = firstX;
			endY = firstY + 1;
		}
		check[firstX][firstY] = 1;
		check[endX][endY] = 1;
		endx = endX;
		endy = endY;
		v.push_back(make_pair(endX, endY));
		for (int i = 0;i < g;i++) {//i는 세대
			curve();
		}
	}
	int result = 0;
	int DX[3] = {0,1,1};
	int DY[3] = {1,0,1};
	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			if (check[i][j] == 1) {
				int cnt = 0;
				for (int k = 0;k < 3;k++) {					
					int newX = i + DX[k];
					int newY = j + DY[k];
					if (newX >= 0 && newX < 101 && newY >= 0 && newY < 101) {
						if (check[newX][newY] == 1) {
							cnt++;
						}
						else {
							break;
						}
					}
				}
				if (cnt == 3) {
					result++;
				}
			}
		}
	}
	cout << result;
	return 0;
}

void curve() {
	int size = v.size()-1;
	for (int i = size;i > 0;i--) {
		int startX = v[i - 1].first;
		int startY = v[i - 1].second;
		int finishX = v[i].first;
		int finishY = v[i].second;
		int dx = finishX - startX;
		int dy = finishY - startY;
		if (dx > 0) {
			endy = endy - 1;
			check[endx][endy]=1;
			v.push_back(make_pair(endx, endy));
		}
		else if (dx < 0) {
			endy = endy + 1;
			check[endx][endy]=1;
			v.push_back(make_pair(endx, endy));			
		}
		else if (dy > 0) {
			endx = endx + 1;
			check[endx][endy]=1;
			v.push_back(make_pair(endx, endy));
		}
		else if (dy < 0) {
			endx = endx - 1 ;
			check[endx][endy]=1;
			v.push_back(make_pair(endx, endy));			
		}
	}
	return;
}


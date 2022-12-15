/*BOJ_)2667번 단지번호붙이기
		 b_d_o_o		*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int Map[25][25];
bool check[25][25];
int N;
int setCnt = 0;
int cnt=0;
vector<int> num;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void DFS(int x, int y);
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		string input;
		cin >> input;
		for (int j = 0;j < N;j++) {
			Map[i][j] = input[j]-48;
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (Map[i][j] == 1) {
				setCnt++;
				DFS(i, j);
				num.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(num.begin(), num.end());
	cout << setCnt<<'\n';
	for (int i = 0;i < num.size();i++) {
		cout << num[i] << '\n';
	}
	return 0;
}

void DFS(int x, int y) {
	cnt++;
	Map[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
			if (Map[new_x][new_y] == 1) {
				DFS(new_x,new_y);
			}
		}
	}
}
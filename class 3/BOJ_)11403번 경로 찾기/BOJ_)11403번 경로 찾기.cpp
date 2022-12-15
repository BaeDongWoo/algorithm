/*BOJ_)11403번 경로 찾기
		b_d_o_o			*/
#include<iostream>
#include<vector>
using namespace std;
int N;
int arr[100][100];
vector<int> v[100];
int check[100][100]={0,};
void DFS(int x,int y);
int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v[i].push_back(j);
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (v[i].size()) {
			DFS(i,i);
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << check[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
void DFS(int x,int y) {
	for (int i = 0;i <v[y].size();i++) {
		int new_y = v[y][i];
		if (check[x][new_y] == 0) {
			check[x][new_y] = 1;
			DFS(x, new_y);
		}
	}
}
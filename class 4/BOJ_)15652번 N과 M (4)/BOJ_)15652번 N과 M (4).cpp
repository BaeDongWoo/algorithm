/*BOJ_)15652¹ø N°ú M(4)
		 b_d_o_o		*/
#include <iostream>
using namespace std;
int N, M;
bool check[9] = { 0, };
int num[9] = { 0, };
void DFS(int cnt, int a);
int main() {
	cin >> N >> M;
	DFS(0, 1);
	return 0;
}
void DFS(int cnt, int a) {
	if (cnt == M) {
		for (int i = 0;i < 9;i++) {
			if (num[i] != 0) {
				cout << num[i] << ' ';
			}
		}	
		cout << '\n';
		return;
	}
	for (int i = a; i <= N;i++) {
		check[i] = 1;
		num[cnt] = i;
		DFS(cnt + 1, i);
		check[i] = 0;
	}
}

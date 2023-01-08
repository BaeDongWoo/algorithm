/*BOJ_)15654¹ø N°ú M (5)
		b_d_o_o		*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
const int MAXN = 10;
int N, M;
int arr[MAXN] = { 0, };
int check[MAXN] = { 0, };
int printCheck[MAXN] = { 0, };
void DFS(int cnt);
int main() {
	int num;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> printCheck[i];
	}
	sort(printCheck, printCheck + N);
	DFS(0);
	return 0;
}
void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0;i < M;i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0;i < N;i++) {
		if (check[i] == 0) {
			arr[cnt] = printCheck[i];
			check[i] = 1;
			DFS(cnt + 1);
			check[i] = 0;
		}
	}
	return;
}
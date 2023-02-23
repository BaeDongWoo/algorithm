/*DX_) 최장 공통 부분 수열
		b_d_o_o		*/
#include <iostream>
#include <string>
using namespace std;
int matrix[1001][1001];

int main() {
	int T;
	cin >> T;
	for (int TC = 1;TC <= T;TC++) {
		string a, b;
		cin >> a >> b;
		for (int i = 1;i <= a.size();i++) {
			for (int j = 1;j <= b.size();j++) {
				if (a[i - 1] == b[j - 1]) {
					matrix[i][j] = matrix[i - 1][j - 1] + 1;
				}
				else {
					matrix[i][j] = max(matrix[i][j - 1],matrix[i-1][j]);
				}
			}
		}
		cout <<"#"<<TC<<' '<< matrix[a.size()][b.size()]<<'\n';
	}
	return 0;
}

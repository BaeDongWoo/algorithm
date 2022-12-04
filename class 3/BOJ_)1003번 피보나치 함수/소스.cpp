/*BOJ_)1003번 피보나치
		b_d_o_o		*/
#include <iostream>
#include <utility>

using namespace std;
int z[42] = { 1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T,N;
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> N;
		for (int j = 2;j <= N+1;j++) {
			z[j] = z[j - 1] + z[j - 2];
			
		}
		cout << z[N] << " " << z[N+1]<<'\n';
	}
	return 0;
}
//dp 방식 


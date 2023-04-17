/*BOJ_)7795번 먹을 것인가 먹힐 것인가
			b_d_o_o				*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		vector<int> A;
		vector<int> B;
		int ans=0;
		cin >> n >> m;
		for (int i = 0;i < n;i++) {
			int num;
			cin >> num;
			A.push_back(num);
		}
		for (int i = 0;i < m;i++) {
			int num;
			cin >> num;
			B.push_back(num);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		for (int i = 0;i < A.size();i++) {
			for (int j = 0;j < B.size();j++) {
				if (A[i] > B[j]) {
					ans++;
				}
			}
		}
		cout << ans<<'\n';
	}
}

//a랑 b를 비교하다가 a보다 b가 크거나 같으면 a한칸이동 비교
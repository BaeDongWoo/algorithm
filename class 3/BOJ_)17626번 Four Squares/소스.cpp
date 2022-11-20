/*BOJ_)17626¹ø FourSquares
		b_d_o_o			*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50001;
int arr[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 1;i*i <= n;i++) {
		if (i * i <= n) {
			arr[i * i] = 1;
		}
	}
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4;i <= n;i++) {
		if (arr[i] != 0) {
			continue;
		}
		else {
			for (int j = 4;j <= n;j++) {
				arr[j] = arr[1] + arr[j - 1];
				for (int k = 2;k * k <= j;k++) {
					arr[j] = min(arr[j],1+arr[j-k*k]);
				}
			}
		}
	}
	cout << arr[n];
	return 0;
}

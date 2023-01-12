/*BOJ_) 1463번 1로 만들기		
		b_d_o_o			*/
#include <iostream>
using namespace std;
int x;
const int MAXN = 10000001;
int arr[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x;
	arr[1] = 0;
	arr[2] = 1;
	for (int i = 3;i <= x;i++) {
		arr[i] = arr[i - 1]+1;//이전값에 -1을 하는 경우의 최소값
		if (i%3==0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);//-1하는 경우의 최소값과 이전 3으로 나누었던 값에 +1한 값을 비교
		}										
		if (i % 2==0) {
			arr[i] = min(arr[i] , arr[i / 2] + 1);//-1하는 경우의 최소값과 이전 2으로 나누었던 값에 +1한 값을 비교
		}
	}
	cout << arr[x] << '\n';
	return 0;
}
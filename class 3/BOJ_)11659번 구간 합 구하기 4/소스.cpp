/*BOJ_)11659번 구간 합 구하기 4
			b_d_o_o			*/
#include <iostream>
using namespace std;
const int MAXN = 100001;
int arr[MAXN];
int arr_s[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	int I, J;
	for (int i = 1;i <= N;i++) {
		arr_s[i] = arr_s[i - 1]+arr[i];//누적합을 새로운 배열에 저장
	}
	while (M--) {
		cin >> I >> J;
		cout << arr_s[J] - arr_s[I-1]<<'\n';//원하는 범위의 누적합을 출력
	}
	return 0;
}

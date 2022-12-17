/*BOJ_)13458번 시험감독 -SW기출
			b_d_o_o			*/
#include<iostream>
using namespace std;
const int MAXN = 1000000;
int arr[MAXN];
int main() {
	int N, B, C;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	cin >> B >> C;
	long long cnt = 0;
	int num;
	for (int i = 0;i < N;i++) {
		if (arr[i] <= B) {
			cnt++;
		}
		else {
			num = arr[i] - B;
			cnt++;
			if (num % C == 0) {
				cnt += num / C;
			}
			else {
				cnt += (num / C) + 1;
			}
		}
	}
	cout << cnt;
	return 0;
}
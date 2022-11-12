/*BOJ_)11399¹ø ATM
	b_d_o_o		*/
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
int p[MAXN];
int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> p[i];
	}
	sort(p, p + N);
	int sum = 0;
	int arr[MAXN];
	for (int i = 0;i < N;i++) {
		sum += p[i];
		arr[i] = sum;
	}
	int total = 0;
	for (int i = 0;i < N;i++) {
		total += arr[i];

	}
	cout << total;
	return 0;
}
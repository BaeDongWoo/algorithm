#include<iostream>
using namespace std;
int check(int k) {
	while (k!=0) {
		if (k % 1000 == 666) {
			return 1;
		}
		k /= 10;
	}
	return 0;
}
int main() {
	int a, i = 1, k = 666;
	cin >> a;
	while (a >= i) {
		if (check(k)==1)
			i++;
		k++;
	}
	cout << k - 1;
	return 0;
}
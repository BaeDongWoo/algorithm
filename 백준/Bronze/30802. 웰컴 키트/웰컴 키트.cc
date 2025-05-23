
/*BOJ_)30802번 웰컴키트*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N,T,P;
	double sizeList[6];
	int totalT = 0;
	cin >> N;
	for (int i = 0;i < 6;i++) {
		cin >> sizeList[i];
	}
	cin >> T >> P;
	for (int i = 0;i < 6;i++) {
		totalT += ceil(sizeList[i] / T);
	}
	cout << totalT << '\n';
	cout << N / P << ' ' << N % P;
}
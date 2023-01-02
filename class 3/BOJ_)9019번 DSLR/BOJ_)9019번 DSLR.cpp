/*BOJ_)9019¹ø DSLR
		b_d_o_o		*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
int T, A, B;
const int MAXN = 10001;
void BFS(int num, int target);
int D(int num);
int S(int num);
int L(int num);
int R(int num);
int main() {
	cin >> T;
	while (T--) {
		cin >> A >> B;
		BFS(A, B);
	}
	return 0;
}
/*int a = num / 1000;
int b = (num % 1000) / 100;
int c = ((num % 1000) % 100) / 10;
int d = ((num % 1000) % 100) % 10;*/
void BFS(int num, int target) {
	bool check[MAXN] = { 0, };
	check[num] = 1;
	string str;
	queue <pair<int, string>> q;
	q.push(make_pair(num, ""));
	while (!q.empty()) {
		int x = q.front().first;
		string a = q.front().second;
		q.pop();
		if (x == target) {
			cout << a<<"\n";
			return;
		}
		else {
			int d = D(x);
			int s = S(x);
			int l = L(x);
			int r = R(x);
			if (check[d] == 0) {
				check[d] = 1;
				q.push(make_pair(d, a + "D"));
			}
			if (check[s] == 0) {
				check[s] = 1;
				q.push(make_pair(s, a + "S"));
			}
			if (check[l] == 0) {
				check[l] = 1;
				q.push(make_pair(l, a + "L"));
			}
			if (check[r] == 0) {
				check[r] = 1;
				q.push(make_pair(r, a + "R"));
			}
		}
	}
}
int D(int num) {
	int n = num * 2;
	if (n >= 10000) {
		n = n % 10000;
	}
	return n;
}
int S(int num) {
	int n;
	if (num == 0) {
		if (B != 0) {
			n = 9999;
		}
	}
	else {
		n = num - 1;
	}
	return n;
}
int L(int num) {
	int a = num / 1000;
	int b = (num % 1000) / 100;
	int c = ((num % 1000) % 100) / 10;
	int d = ((num % 1000) % 100) % 10;
	int n = ((b * 10 + c) * 10 + d) * 10 + a;
	return n;
}
int R(int num) {
	int a = num / 1000;
	int b = (num % 1000) / 100;
	int c = ((num % 1000) % 100) / 10;
	int d = ((num % 1000) % 100) % 10;
	int n = ((d * 10 + a) * 10 + b) * 10 + c;
	return n;
}
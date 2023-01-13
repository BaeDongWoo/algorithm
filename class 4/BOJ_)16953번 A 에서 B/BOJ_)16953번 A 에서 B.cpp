/*BOJ_)16953¹ø A ¿¡¼­ B
		b_d_o_o		*/
#include <iostream>
#include <queue>
using namespace std;
long long A, B;
long long BFS(long long num, int cnt);
int main() {
	cin >> A >> B;
	cout<<BFS(A, 1);
	return 0;
}
long long BFS(long long num, int cnt) {
	queue <pair<long long, long long>> q;
	q.push(make_pair(num, cnt));
	while (!q.empty()) {
		long long n = q.front().first;
		long long c = q.front().second;
		q.pop();
		if (n == B) {
			return c;
		}
		long long mulTwo = n * 2;
		long long RPOne = (n * 10) + 1;
		if (mulTwo <= B) {
			q.push(make_pair(mulTwo, c + 1));
		}
		if (RPOne <= B) {
			q.push(make_pair(RPOne, c + 1));
		}
	}
	if (q.empty()) {
		return-1;
	}
}
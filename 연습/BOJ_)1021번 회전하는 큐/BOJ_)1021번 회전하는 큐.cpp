/*BOJ_)1021번 회전하는 큐
		b_d_o_o		*/
#include <iostream>
#include <deque>
#include<queue>
using namespace std;
deque<int> dq;
int result;
int main() {
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++ ) {
		dq.push_back(i);
	}
	int M;
	cin >> M;
	for (int i = 0;i < M;i++) {
		int num;
		cin >> num;
		for (int j = 0;j < dq.size();j++) {
			if(dq[j]==num){
				int cnt = 0;
				if (j > dq.size() - j) {//뒤가 더 가까울 때
					while (dq.front()!=num) {
						int n = dq.back();
						dq.pop_back();
						dq.push_front(n);
						cnt++;
					}
				}
				else if (j <= dq.size() - j) {// 앞이 더 가까울 때
					while (dq.front() != num) {
						int n = dq.front();
						dq.pop_front();
						dq.push_back(n);
						cnt++;
					}
				}
				dq.pop_front();
				result += cnt;
				break;
			}
		}
	}
	cout << result;
	return 0;
}
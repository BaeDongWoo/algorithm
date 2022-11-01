/*BOJ_)1927번 최소 힙
		b_d_o_o		*/
#include <iostream>
#include<queue>
#include<functional>

using namespace std;
priority_queue<int, vector<int>, greater<int>> q; //greter 정렬 >> top이 가장 작은수
int main() {
	int N; cin >> N;
	while (N--) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int X; cin >> X;
		if (X != 0) {//X값이 0이 아니면 X 값을 푸쉬
			q.push(X);
		}
		else {
			if (!q.empty()) {//X값이 0이고 q가 비어있지 않으면 
				cout << q.top()<<'\n';//top>>가장 작은수
				q.pop();//top 삭제
			}
			else {
				cout << 0<<'\n';//비어 있다면 0출력
			}
		}
	}
	return 0;
}
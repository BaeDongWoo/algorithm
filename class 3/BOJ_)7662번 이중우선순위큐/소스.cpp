/*BOJ_)7662번 이중 우선순위 큐
			b_d_o_o			*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;
const int MAXN = 1000001;

bool visit[MAXN];
int main() {
	int T, K;
	string input;
	int inputNumber;
	cin >> T;
	while (T--) {
		cin >> K;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxQ;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
		for (int i = 0;i < K;i++) {
			cin >> input >> inputNumber;
			if (input == "I") {
				maxQ.push({ inputNumber,i });
				minQ.push({ inputNumber,i });
				visit[i] = 1;
			}
			if (input == "D") {
				if (inputNumber == 1) {
					while (!maxQ.empty() && !visit[maxQ.top().second]) {
						maxQ.pop();
					}
					if (!maxQ.empty()) {
						visit[maxQ.top().second] = 0;
						maxQ.pop();
					}
				}
				if (inputNumber == -1) {
					while (!minQ.empty() && !visit[minQ.top().second]) {
						minQ.pop();
					}
					if (!minQ.empty()) {
						visit[minQ.top().second] = 0;
						minQ.pop();
					}
				}
			}
		}
		while (!maxQ.empty() && !visit[maxQ.top().second]) {
			maxQ.pop();
		}
		while (!minQ.empty() && !visit[minQ.top().second]) {
			minQ.pop();
		}
		if (!maxQ.empty() || !minQ.empty()) {
			cout << maxQ.top().first << ' ' << minQ.top().first << '\n';
		}
		else {
			cout << "EMPTY" << '\n';
		}
	}
}

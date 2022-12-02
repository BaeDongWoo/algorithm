/*BOJ_)1931번 회의실 배정
		b_d_o_o			*/
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100000;
int N;
int a, b;
int endTime,startTime;
int result;
pair<int,int> meetingTime[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> meetingTime[i].second >> meetingTime[i].first;
	}
	sort(meetingTime, meetingTime + N);
	int cnt = 1;
	if (N == 1) {
		cnt = 1;
	}
	endTime = meetingTime[0].first;
	for (int j = 1 ;j < N;j++) {
		startTime = meetingTime[j].second;
		if (endTime <= startTime) {
			endTime = meetingTime[j].first;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
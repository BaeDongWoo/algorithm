#include <iostream>
using namespace std;

int solution(int N)
{
    int ans = 0;
	int cnt = 1;
	while(N>1) {
		if (N % 2 == 0) N /= 2;
		else {
			cnt++;
			N /= 2;
		}
	}
    return cnt;
}
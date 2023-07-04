#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int atemp=a;
    int btemp=b;
    while(atemp!=btemp){
        answer++;
        atemp=(atemp+1)/2;
        btemp=(btemp+1)/2;
    }

    return answer;
}
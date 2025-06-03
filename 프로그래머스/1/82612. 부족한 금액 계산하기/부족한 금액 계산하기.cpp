using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    long long pay = 0;
    for(int i = 1 ; i<=count;i++){
        pay += i*price;
    }
    if(pay>money) answer = pay-money;
    return answer;
}
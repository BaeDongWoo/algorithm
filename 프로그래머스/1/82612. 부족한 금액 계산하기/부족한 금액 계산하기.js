function solution(price, money, count) {
    var answer = 0;
    let pay = 0;
    for (let i  = 1;i<=count;i++){
        pay += price *i;
    }
    if (pay>money) answer = (pay-money);
    return answer;
}
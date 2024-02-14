function solution(a, b, n) {
    let answer = 0;
    let cola=0;
    while(n>=a){
        cola=Math.floor((n/a));
        answer +=cola*b;
        n=(cola*b)+(n%a);
    }
    return answer;
}
function solution(a, b) {
    var answer = 0;
    a.map((temp, idx)=>{answer += temp*b[idx];});
    return answer;
}
function solution(numbers) {
    let answer = 45;
    numbers.map((number)=>answer-=number);
    
    return answer;
}
function solution(n) {
    var answer = 0;
    let array = [...n.toString()];
    array.sort((a,b)=>b-a);
    answer= Number(array.join(''));
    console.log(answer);
    return answer;
}
function solution(n) {
    var answer = 0;
    let arr = [];
    while(n>=3){
        const temp = n%3;
        n=Math.floor(n/3);
        arr.push(temp);
    }
    arr.push(n);
    let str = arr.join('');
    answer =parseInt(str,3);
    return answer;
}
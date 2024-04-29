function solution(n, left, right) {
    var answer = [];
    for(let i = left;i<=right;i++){
        let num=Math.max(parseInt(i/n),i%n)+1;
        answer.push(num);
    }
    console.log(answer);
    return answer;
}
/*
1 2 3 
2 2 3
3 3 3
*/
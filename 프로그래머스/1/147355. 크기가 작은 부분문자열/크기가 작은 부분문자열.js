function solution(t, p) {
    var answer = 0;
    const range=p.length-1;
    for(let i=0;i<t.length-range;i++){
        let temp = t[i];
        for(let j=i+1;j<=i+range;j++){
            temp += t[j];
        }
        if(Number(p)>=Number(temp)) answer++;
    }
    return answer;
}
// 길이가 7 => 5까지 
// p의 길이 - 1까지 
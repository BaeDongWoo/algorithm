function solution(n) {
    var answer = [];
    for(let i=2;i<=n;i++){
        answer[i]=1;
    }
    for(let i = 2;i<=n;i++){
        if(answer[i]===0)continue;
        for(let j=i+i;j<=n;j+=i){
            answer[j]=0;
        }
    }
    const result = answer.filter((num)=>num===1);
    
    return result.length;
}


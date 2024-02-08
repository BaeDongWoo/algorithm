function solution(s) {
    var answer = 0;
    let cnt1=0;
    let cnt2=0;
    for (let i = 0;i<s.length;i++){
        const target=s[i];
        for (let j = i;j<s.length;j++){
            const temp=s[j];
            console.log(i+temp+j);
            if(target===temp) cnt1++;
            else cnt2++;
            console.log(cnt1,cnt2);
            if(cnt1===cnt2){
                answer++;
                cnt1=0;
                cnt2=0;
                i=j;
                break;
            }
        }
        if(cnt1!==cnt2){
            answer++;
            break;
        }
        
    }
    return answer;
}

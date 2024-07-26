function solution(progresses, speeds) {
    let answer = [];
    let days = [];
    for(let i = 0;i<progresses.length;i++){
        const day = Math.ceil((100 - progresses[i])/speeds[i]);
        days.push(day);
    }
    let p = 0;
    let pp = 0;
    let cnt =0;
    console.log(days);
    while(p !== days.length){
        if(days[p]>=days[pp]){
            cnt++;
            pp++;
        }
        else{
            answer.push(cnt);
            cnt=0;
            p=pp;
        }
    }
    return answer;
}
/*


*/
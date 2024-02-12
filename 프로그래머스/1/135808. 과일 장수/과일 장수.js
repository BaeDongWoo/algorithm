function solution(k, m, score) {
    var answer = 0;
    let appleBox=[];
    score.sort((a,b)=>b-a);
    for(let i =0;i<score.length;i++){
        appleBox.push(score[i]);
        if(appleBox.length===m){
            answer+=appleBox[m-1]*m;
            appleBox=[];
        }
    }
    return answer;
}
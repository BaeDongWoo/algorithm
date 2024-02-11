function solution(k, score) {
    let answer = [];
    let hallOfFame=[];
    for (let i =0;i<score.length;i++){
        if(hallOfFame.length<k){
            hallOfFame.push(score[i]);
        }
        else {
            if(score[i]>hallOfFame[0]){
                hallOfFame[0]=score[i];
            }
        }
        hallOfFame.sort((a,b)=>a-b);
        answer.push(hallOfFame[0]);
    }
    return answer;
}
// k = 명예의 전당 명수
// score는 점수 
// 
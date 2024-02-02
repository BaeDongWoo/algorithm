function solution(friends, gifts) {
    var answer = 0;
    let table = Array.from(Array(friends.length), () => Array(friends.length).fill(0));
    let giftScore = new Map();
    for(let i =0;i<friends.length;i++){
        giftScore.set(friends[i],0);
    }
    for(let i =0;i<gifts.length;i++){
        let AB=gifts[i].split(' ');
        let AIndex = friends.findIndex((e)=>e===AB[0]);
        let BIndex = friends.findIndex((e)=>e===AB[1]);
        table[AIndex][BIndex]++;
        
        let getAScore = giftScore.get(AB[0]);
        giftScore.set(AB[0],getAScore+1);
        let getBScore = giftScore.get(AB[1]);
        giftScore.set(AB[1],getBScore-1);
    }
    for(let i=0;i<table.length;i++){
        let score = 0;
        for(let j=0;j<table[i].length;j++){
            if(i!==j){
                if(table[i][j]>table[j][i]){
                    score++;
                }
                else if(table[i][j]===table[j][i]){
                    let getAScore = giftScore.get(friends[i]);
                    let getBScore = giftScore.get(friends[j]);
                    if(getAScore>getBScore){
                        score++;
                    }
                }
            }
        }
        
        if(score>answer) answer=score;
    }
    return answer;
}



// A가 B에게 선물을 5번 => B가 A에게 선물을 3번 다음달 B가 -> A에게 선물 1개  
// 선물을 주고 받은 기록이 x or 같다면 선물 지수가 작은사람 -> 선물 지수가 큰사람
// 선물 지수 = 준 선물 - 받은 선물
// 선물 지수가 같다면 주고 받기 x
// muzi:{frodo : 0, ryan : 0, neo : 0};
// array=[{muzi:{frodo : 0, ryan : 0, neo : 0}}]
// [o] 각 친구의 선물지수를 저장
// 2차원 배열에 저장
// findIndex로 각 index를 찾아서 해당 배열에 저장 
// ex) [[0,0,2,0],[3,0,0,0],[1,1,0,0],[1,0,0,0]]
// []서로 선물을 주었는지 확인
// []선물을 주었다면 더 많이 준 사람에게 다음달에 선물
// []선물을 주었던 갯수가 같거나 0개이면 선물 지수가 작은 사람이 다음달에 선물
// []선물 지수 마저 같다면 선물 x 
// []각 캐릭터마다 다음달 선물 갯수를 저장하고 갯수를 반환
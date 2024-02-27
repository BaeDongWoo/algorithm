function solution(N, stages) {
    var answer = [];
    let gamer = stages.length; // 총 게이머의 수 
    let failureRate = []; // 실패율을 저장할 리스트
    for (let i = 1;i<=N;i++){
        const stagePeople = stages.filter((e)=>e===i).length; // 스테이지별 인원수
        const rate = [stagePeople/gamer,i]; // 실패율과 , 스테이지를 저장
        failureRate.push(rate); 
        gamer-=stagePeople;// 다음 스테이지의 게이머 수 
    }
    failureRate.sort((a,b)=>{// 실패율과 스테이지에 따라 정렬
        if(a[0]===b[0]){
            return a[1]-b[1];
        }
        else{
            return b[0]-a[0];
        }
    });
    failureRate.map((arr)=> answer.push(arr[1]));// 스테이지만 출력
    return answer;
}

// 실패율 
// 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수  = 현재 스테이지에 있는 사람들 
// 스테이지에 도달한 플레이어 수 = 현재 스테이지 + 이후 스테이지에 있는 사람들

// 각 스테이지별 머무르고 있는사람들 인원 저장
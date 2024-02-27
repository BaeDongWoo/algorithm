function solution(N, stages) {
    var answer = [];
    let gamer = stages.length;
    let people = new Array(N+1);
    for (let i=1;i<=N ;i++){    
        people[i]=stages.filter((e)=>e===i).length; 
    }
    let failureRate = [];
    for (let i = 1;i<people.length;i++){
        const rate = [people[i]/gamer,i];
        failureRate.push(rate);
        gamer-=people[i];
    }
    failureRate.sort((a,b)=>{
        if(a[0]===b[0]){
            return a[1]-b[1];
        }
        else{
            return b[0]-a[0];
        }
    });
    failureRate.map((arr)=> answer.push(arr[1]));
    return answer;
}

// 실패율 
// 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수  = 현재 스테이지에 있는 사람들 
// 스테이지에 도달한 플레이어 수 = 현재 스테이지 + 이후 스테이지에 있는 사람들

// 각 스테이지별 머무르고 있는사람들 인원 저장
// 
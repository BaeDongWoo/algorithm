function solution(signals) {
    var answer = -1;
    let maxTime = 1;
    let sec = 0;
    let timeArr = signals.map((sig)=>{
        let time = 0;
        sig.forEach((num)=>{
          time +=num
        })
        maxTime *=time;
        return time;
    });
    while(sec < maxTime){
        let flag = false;
        
        for(let i=0; i<signals.length;i++){
           let minY = signals[i][0];
           let maxY = signals[i][0] + signals[i][1];
           if(minY >= (sec % timeArr[i])+1 || maxY < (sec % timeArr[i])+1) break;
           if(signals.length === i+1) {
               flag = true;
           }
        }
        
        if(flag){
            return sec+1;
        } 
        else sec++;
    }
    return answer;
}

// 현재 시간을 g + y + r 한 값의 나머지가 g 초과 g + y 이하의 숫자 인지를 돌면서 판단 그렇지 않으면 반복 종료 후
// 시간을 더해서 다시 확인 
// 제한은 흠 맥스 시간은  g + y + r 의값을 다 곱한 시간까지 못찾으면 -1return 하면되나,, 
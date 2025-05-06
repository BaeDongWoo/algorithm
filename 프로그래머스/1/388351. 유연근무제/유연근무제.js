function solution(schedules, timelogs, startday) {
    var answer = 0;
    for(let i = 0;i<schedules.length;i++){
        let hour = Math.floor(schedules[i]/100);
        let min = schedules[i]%100 + 10;
        if(min>=60){
            hour +=1;
            min %=60; 
        }
        const maxTime = hour * 100 + min;
        let day = startday;
        let count = 0;
        for(let j = 0;j<timelogs[i].length;j++){
            const nextDay = day % 7 + 1;        
            if(day === 6 || day === 7){
                day = nextDay;
                continue;
            }
            const arrivalTime = timelogs[i][j];
            if(arrivalTime<=maxTime) count++;
            day=nextDay;
        }
        if(count === 5) answer++;
    }
    return answer;
}
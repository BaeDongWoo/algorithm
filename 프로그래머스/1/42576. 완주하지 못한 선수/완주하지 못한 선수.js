function solution(participant, completion) {
    var answer = '';
    participant.sort();
    completion.sort();
    const findName=()=>{
        for(let i=0;i<participant.length;i++){
            if(participant[i]!==completion[i]) {
                 return participant[i];
            }
        }
       return participant[participant.length-1]
    }
    answer=findName();
    return answer;
}
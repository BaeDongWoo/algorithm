function solution(food) {
    var answer = '';
    for(let i=1;i<food.length;i++){
        const num=Math.floor(food[i] / 2);
        for(let j=0;j<num;j++){
            answer+=i;
        }
    }
    answer+=0;
    for(let i=answer.length-2;i>=0;i--){
        answer+=answer[i];
    }
    return answer;
}
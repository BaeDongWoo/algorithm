function solution(numbers) {
    var answer = [];
    let score =[];
    for (let i=0;i<numbers.length-1;i++){
        for (let j=i+1;j<numbers.length;j++){
            let temp = numbers[i]+numbers[j];
            score.push(temp);
    }
    }
    answer = [...new Set(score)];
    answer.sort((a,b)=>a-b);
    return answer;
}
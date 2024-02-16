
function solution(number) {
    let answer = 0;
    let arr = [];
    const recusive =(start)=>{
        if(arr.length===3){
            let score = 0;
            arr.map((a)=>{score+=a});
            if(score===0) {
                answer++;
                return;
            }
        }
        for(let i = start;i<number.length;i++){
            arr.push(number[i]);
            recusive(i+1);
            arr.pop();
        }
    }
    recusive(0);
    return answer;
}

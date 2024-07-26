function solution(arr)
{
    let answer=[];
    let lastNum = -1;
    arr.map((num)=>{
        if(lastNum!== num) {
            answer.push(num);
            lastNum = num;
        }
    })
    return answer;
}
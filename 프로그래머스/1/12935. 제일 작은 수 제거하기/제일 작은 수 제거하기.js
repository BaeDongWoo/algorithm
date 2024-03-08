function solution(arr) {
    var answer = [];
    const minNum = Math.min(...arr);
    arr=arr.filter((num)=>num!==minNum);
    if(arr.length===0){
        answer.push(-1);
    }
    else{
        answer = arr;
    }
    console.log(answer);
    return answer;
}
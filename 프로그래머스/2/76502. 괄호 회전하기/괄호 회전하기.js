
function solution(s) {
    var answer = 0;
    let arr = s.split('');
    for(let i = 0;i<arr.length;i++){
        if(run(arr)) answer++;
        const temp = arr.shift();
        arr.push(temp);
    }
    return answer;
}
const run =(s)=>{
    let tempArr= [];
    for(let i =0;i<s.length;i++){
        if(s[i]==="["|| s[i]==="{"||s[i]==="("){
            tempArr.push(s[i]);
        }
        else {
            const tempArrPop=tempArr[tempArr.length-1];
            if(tempArrPop==="["&&s[i]==="]"||tempArrPop==="{"&&s[i]==="}"||tempArrPop==="("&&s[i]===")"){
                tempArr.pop();
            }
            else {
                return false;
            }
        }
    }
    if(tempArr.length===0) return true;
    else return false;
}
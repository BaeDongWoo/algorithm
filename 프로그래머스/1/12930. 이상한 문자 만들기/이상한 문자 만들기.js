function solution(s) {
    var answer = '';
    let arr = s.split(' '); //공백으로 문자열을 나누어 배열에 저장 
    let str = '' ;
    for(let i = 0 ;i<arr.length; i++){
        str = arr[i];
        for(let j =0;j<str.length;j++){
            if(j%2 ===0){ //첫번째 문자거나 짝수번째일때 대문자로 변경
                answer += str[j].toUpperCase();
            }
            else{
                answer += str[j].toLowerCase();       
            }
        }
        answer += " ";
    }
    answer = answer.substr(0,answer.length-1);
    return answer;
}
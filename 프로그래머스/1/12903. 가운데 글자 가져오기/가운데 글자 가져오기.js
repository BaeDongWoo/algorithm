function solution(s) {
    var answer = '';
    let index = Math.floor(s.length/2);
    if(s.length%2 === 0){
        answer+=s[index-1];
        answer+=s[index];
    }
    else{
        answer = s[index];
    }
    return answer;
}
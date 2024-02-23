function solution(absolutes, signs) {
    var answer = 123456789;
    let T=0;
    let F=0;
    for(let i =0;i<absolutes.length;i++){
        if(!signs[i])F+=absolutes[i];
        else T+=absolutes[i];
    }
    answer = T-F;
    return answer;
}
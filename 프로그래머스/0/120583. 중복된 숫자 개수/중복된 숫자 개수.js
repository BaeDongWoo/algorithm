function solution(array, n) {
    var answer = array.filter((e)=>e===n).length;
    return answer;
}
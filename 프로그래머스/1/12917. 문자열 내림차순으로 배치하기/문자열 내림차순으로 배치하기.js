function solution(s) {
    var answer = '';
    let array = s.split('');
    array.sort((a,b)=>b.charCodeAt()-a.charCodeAt());
    return array.join('');
}
function solution(ingredient) {
    var answer = 0;
    let burger=[];
    for (let i=0;i<=ingredient.length;i++){
        burger.push(ingredient[i]);
        if(burger.slice(-4).join('')==='1231'){
            burger.splice(-4);
            answer++;
        }
    }
    return answer;
}
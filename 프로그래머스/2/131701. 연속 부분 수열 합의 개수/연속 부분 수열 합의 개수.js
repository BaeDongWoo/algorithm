function solution(elements) {
    var answer = 0;
    let arr = [];
    for(let i = 0;i<elements.length;i++){
        for(let j = 0;j<elements.length;j++){
            let num=0;
            for(let k = 0;k<=i;k++){
                const index = (j+k)%elements.length;
                num+=elements[index];  
            }
            arr.push(num);
            
        }
    }
    arr= new Set(arr);
    answer = [...arr];
    return answer.length;
}

function solution(babbling) {
    var answer = 0;
    const babArray= [ "aya", "ye", "woo", "ma"];// 순서대로 0,1,2,3
    for(let i=0;i<babbling.length;i++){
        let bab= Array.from(babbling[i]);
        let tempTarget=-1;
        while(bab.length>1){  
            if(bab.slice(0,2).join('')===babArray[1] || bab.slice(0,2).join('')===babArray[3]){
                const targetIndex=babArray.findIndex((b)=>b===bab.slice(0,2).join(''));
                if(tempTarget===targetIndex) break;
                else{
                    tempTarget=targetIndex;
                    bab.splice(0,2);
                }
            }
            else if(bab.slice(0,3).join('')===babArray[0] || bab.slice(0,3).join('')===babArray[2]){
                const targetIndex=babArray.findIndex((b)=>b===bab.slice(0,3).join(''));
                if(tempTarget===targetIndex) break;
                else{
                    tempTarget=targetIndex;
                    bab.splice(0,3);
                }
            }
            else {
                break;
            }
        }
        if(bab.length===0)answer++;
    }
    return answer;
}
//
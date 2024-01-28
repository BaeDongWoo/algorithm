function solution(name, yearning, photo) {
    var answer = [];
    for(let i=0;i<photo.length;i++){
        let num=0;
        for(let j=0;j<photo[i].length;j++){
            let index=name.findIndex((e)=>e===photo[i][j]);
            if(index!==-1)num+=yearning[index];
        }
        answer.push(num);
    }
    return answer;
}
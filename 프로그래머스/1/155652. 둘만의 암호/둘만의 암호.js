function solution(s, skip, index) {
    var answer = '';
    for(let i = 0;i<s.length;i++){
        let ss = s[i].charCodeAt();
        let p=index;
        for (let j = 0;j<p;j++){
            ss++;
            if(ss>122) ss = 97;
            
            for(let k = 0;k<skip.length;k++){
                let sss = skip[k].charCodeAt();
                if(ss === sss ) p++;
            }
            
        }
        answer+=String.fromCharCode(ss);
    }
    return answer;
}
function solution(s, n) {
    var answer = '';
    const upperCase = 'Z'.charCodeAt(); 
    const lowerCase = 'z'.charCodeAt();
    const array = s.split('')
    for(let i= 0;i<array.length;i++){
        let code = array[i].charCodeAt();
        if(65<=code&&code<=upperCase){
            code += n;
            if(code > upperCase) code = 65+code%upperCase-1;
        }
        else if(97<=code&&code<=lowerCase){
            code+=n;
            if(code > lowerCase) code = 97+code%lowerCase-1;
           
        }
        answer += String.fromCharCode(code);
    }
    return answer;
}
function solution(s) {
    var answer = [];
    let arr = [];
    let tempArr = [];
    let num = '';
    for(let i = 0 ; i<s.length;i++){
        if (!isNaN(Number(s[i]))){
            num+=s[i];
        }
        else if(s[i]===","){
            if(num !== '') {
                tempArr.push(Number(num));
                num='';
            }
        }
        else if(s[i]==="}"){
            if(num!==''){
                tempArr.push(Number(num));
                num='';
            }
            if(tempArr.length!==0){
                arr.push(tempArr);
            }
            tempArr = [];
        }
         s[i]==="x";
    }
    let size = 1;
    arr.sort((x,y)=>x.length-y.length);
    arr.map((numArr)=>{
        numArr.map((num)=>{
            if(!answer.includes(num)) answer.push(num);
        });
        });
    return answer;
}

/*
1. {와, 일 경우 x로 문자열 대체 숫자일 경우 새로운 배열을 만들어 넣기
2. }일 경우 1번에서 만들어낸 배열을 arr에 넣기
3. 모든 배열이 완성되었으면 배열의 크기가 작은 것부터 계산 
    3.1 최종 배열에 있는 숫자를 제외한 숫자를 최종 배열에 추가
*/
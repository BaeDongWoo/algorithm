
function solution(n, t, m, p) {
    var answer = '';
    let maxTurn = m * (t-1)+p;
    let turnArr = ["0"];
    let cnt = 1;
    while(turnArr.length < maxTurn){
        const formatNum = format(cnt,n);
        for(let i = 0 ;i<formatNum.length;i++){
            turnArr.push(formatNum[i]);
        }
        cnt++; 
    }
    console.log(turnArr);
    let pointer = 0;
    for(let i=0;i<t;i++){
        pointer = m * i + p;
        answer+=turnArr[pointer-1];
    }
    return answer;
}
const format=(num,n)=>{ // n진법으로 변환
        let formatNum = "";
        while(num>=n){
            let mod = num % n;
            if(mod >= 10){
                mod = String.fromCharCode(mod % 10 + 65); // 10이상일 경우 아스키 코드로 변환
            }
            num = Math.floor(num/n);
            formatNum = mod + formatNum;
        }
        if(num !== 0) {
            if(num >= 10){
                num = String.fromCharCode(num % 10 + 65); // 10이상일 경우 아스키 코드로 변환
            }
            formatNum = num +formatNum;
        }
        
       return formatNum;
    }
// 여러명이 둥글게 앉아서 숫자를 하나씩 차례대로 말하는 게임
// 첫번째사람은 0 부터 1씩 증가하면서 시작
// 0 1 1 1
/*
미리 구해야할 수가 t개 이면, p차례가 t번 와야하고, p차례가 t번 오기 위해서는 


참가인원 m * t-1번만큼 반복 후 + p번 = 총 순서


숫자 1 부터 증가 시키면서 n진법으로 변환 변환한 숫자를 배열에 push
배열의 크기 === 총 순서가 되면 반복문 종료
*/
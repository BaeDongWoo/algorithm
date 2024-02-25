function solution(numbers, hand) {
    var answer = '';
    const indexList  = [[3,1],[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2]];
    let left = [3,0];
    let right = [3,2];
    for(let i=0;i<numbers.length;i++){
        if(numbers[i]===1||numbers[i]===4||numbers[i]===7) answer+='L';
        else if(numbers[i]===3||numbers[i]===6||numbers[i]===9) answer+='R';
        else {
            let targetIdx=indexList[numbers[i]];
            let lx= Math.abs(left[0]-targetIdx[0]);
            let ly= Math.abs(left[1]-targetIdx[1]);
            let rx= Math.abs(right[0]-targetIdx[0]);
            let ry= Math.abs(right[1]-targetIdx[1]);
            let leftDis = lx+ly;
            let rightDis =rx+ry;
            if(leftDis > rightDis) answer+='R';
            else if(leftDis < rightDis) answer+='L';
            else {
                if(hand==='right') answer+='R';
                else answer+='L';
            }
        }
        if(answer[answer.length-1]==='L') left = indexList[numbers[i]];
        else right = indexList[numbers[i]];
    }
    return answer;
}
//numbers 가 1 4 7 이면 L, nembers 가 3 6 9 이면 R 
//왼손의 현재 위치와 오른손의 현재 위치를 저장
//2 5 8 0의 경우 양손의 현재 위치에서 거리를 계산 

function solution(arr1, arr2) {
    var answer = [];
    for(let i=0;i<arr1.length;i++){
        let tempArr= [];
        for(let j=0;j<arr2[0].length;j++){
            let temp = 0;
            for(let k=0;k<arr1[0].length;k++){
                const num1=arr1[i][k];
                const num2=arr2[k][j];
                temp+=num1*num2;
            }
         
                tempArr.push(temp);
    
           
        }
        answer.push(tempArr);
    }
    return answer;
}
/*
1 4      3 3      15 15
3 2      3 3      15 15
4 1               15 15

2 3 2   5 4 3   22 22 11
4 2 4   2 4 1   36 28 18
3 1 4   3 1 1   29 20 14
*//*
function solution(arr1, arr2) {
    let answer = [];
    let x_length = arr1.length;
    let y_length = arr2[0].length;
    let x1_length = arr1[0].length;


    // arr1.length만큼 반복
    for(let i=0; i<x_length; i++) {
        let temp = [];

        // arr2.length만큼 반복
        for(let j=0; j<y_length; j++) {

            let sum = 0;
            // 내부 행렬 계산 반복
            for(let k=0; k<x1_length; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }

            temp.push(sum)
        }

        answer.push(temp)
    }


    return answer;
}*/
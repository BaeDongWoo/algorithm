function solution(n, arr1, arr2) {
    var answer = [];
    for (let i = 0;i<n;i++){
        let arr1Decoding = decoding(n,arr1[i]);
        let arr2Decoding = decoding(n,arr2[i]);
        let temp = '';
        for(let j= 0;j<n;j++){
            if(arr1Decoding[j]==='1'||arr2Decoding[j]==='1'){
                temp+='#';
            }
            else{
                temp+=' ';
            }
        }
        answer.push(temp);
    }
    
    return answer;
}
const decoding=(size,number)=>{
    let result = '';
    while(number>1){
        result= number%2+result;
        number= Math.floor(number/2);
    }
    result=number+result;
    while(result.length<size){
        result = '0'+result;
    }
    return result;
}
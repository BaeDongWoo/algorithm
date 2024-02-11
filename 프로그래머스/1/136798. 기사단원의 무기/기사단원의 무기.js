function solution(number, limit, power) {
    var answer = 0;
    let arr = new Array(number);
    for(let i = 1;i<=number;i++){
        let cnt =0;
        for(let j=1;j*j<=i;j++){
            if(i%j===0){
                cnt++;
                if(j*j<i)cnt++;
            }
        }
        if(cnt>limit)cnt=power;
        arr[i-1]=cnt;
    }
    arr.map((a)=>answer+=a);
    return answer;
}
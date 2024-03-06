function solution(nums) {
    var answer = 0;
    let number = 0;
    let cnt = 0;
    const checkPrimeNumber=(num)=>{
        let checkPrime =0;
        for(let i =1;i<=num;i++){
            if(num%i===0) checkPrime++;
        }
        if(checkPrime===2)answer++;
    }
    const recursive = (index)=>{
        if(cnt === 3 ){
            console.log(number);
            return checkPrimeNumber(number);
        }
        for(let i = index;i<nums.length; i++){
            number+=nums[i];
            cnt++;
            recursive(i+1);
            cnt--;
            number-=nums[i];
        }
    }
    recursive(0);
    return answer;
}
function solution(priorities, location) {
    var answer = 0;
    let process = priorities.map((pro,idx)=>{return{pro,idx}});
    let run=0;
    while(true){
        let flag = false;
        const target = process.splice(0,1)[0];
        
        for(let i = 0;i<process.length;i++){
            if(process[i].pro > target.pro){
                process.push(target);
                flag=true;
                break;
            }
        }
        if(!flag){
            run++;
            console.log(target,run);
            if(target.idx === location) {
                return run;
            }
            
        }
        if(process.length === 0) break;
    }
}
// 프로세스를 선택(배열의 첫번째)
// 선택한 프로세스의 우선순위를 다른 프로세스의 우선순위 들과 비교
// 선택한 프로세스의 우선순위보다 큰 우선 순위가 있다면 해당 프로세스를 배열 맨뒤에 추가
// 


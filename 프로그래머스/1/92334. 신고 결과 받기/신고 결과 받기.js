function solution(id_list, report, k) {
    let answer = new Array(id_list.length);
    answer.fill(0);
    let map = new Map();
    for(let i=0;i<id_list.length;i++){
        map.set(id_list[i],[]);
    }
    for(let i=0;i<report.length;i++){
        const re = report[i].split(' ');
        const tempData=map.get(re[1]);
        if(!tempData.find((e)=>e===re[0])){
            tempData.push(re[0]);
            map.set(re[1],tempData);
        }
    }
    map.forEach((data)=>{
        if(data.length>=k){
            for(let i=0;i<data.length;i++){
                const index = id_list.findIndex((e)=>e===data[i]);
                answer[index]++;
            }
        }
    })
    return answer;
}
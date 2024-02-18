function solution(id_list, report, k) {
    let answer = new Array(id_list.length);
    answer.fill(0);
    let map = new Map();
    let setReport = [...new Set(report)];
    for(let i=0;i<id_list.length;i++){
        map.set(id_list[i],[]);
    }
    for(let i=0;i<setReport.length;i++){
        const re = setReport[i].split(' ');
        map.get(re[1]).push(re[0]);
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